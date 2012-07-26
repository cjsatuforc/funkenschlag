#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include <math.h>
#include "twi.h"
#include "mag.h"
#include "acc.h"
#include "serial.h"
#include "config.h"

#ifdef USE_MAG

/* HMC5883 */
#define MAG_ADDRESS 0x1E
#define MAG_DATA_REGISTER 0x03
#define MAG_SCALE_FACTOR_13 0.92

#ifndef MAG_ORIENTATION
#define MAG_ORIENTATION(X, Y, Z)  {mag_data[M_X]  = -(X); mag_data[M_Y]  = -(Y); mag_data[M_Z]  = (Z);}
#endif

static int16_t mag_data[3];

static int16_t mag_bearing;

#define M_X 0
#define M_Y 1
#define M_Z 2

void mag_init(void) {
	_delay_ms(100);
	twi_write_reg(MAG_ADDRESS, 0x00, 0x70);
	twi_write_reg(MAG_ADDRESS, 0x01, 0x20);
	twi_write_reg(MAG_ADDRESS, 0x02, 0x00);
}


float _atan2(float y, float x) {
	#define fp_is_neg(val) ((((uint8_t*)&val)[3] & 0x80) != 0)
	float z = y / x;
	int16_t zi = abs((int16_t)(z * 100));
	int8_t y_neg = fp_is_neg(y);
	if ( zi < 100 ) {
		if (zi > 10) {
			z = z / (1.0f + 0.28f * z * z);
		}
		if (fp_is_neg(x)) {
			if (y_neg) z -= M_PI;
			else z += M_PI;
		}
	} else {
		z = (M_PI / 2.0f) - z / (z * z + 0.28f);
		if (y_neg) z -= M_PI;
	}
	return z;
}

void mag_query(void) {
	uint8_t buf[6];
	twi_start(MAG_ADDRESS<<1);
	twi_write(MAG_DATA_REGISTER);
	twi_start(MAG_ADDRESS<<1 | 1);
	for (uint8_t i=0; i<sizeof(buf); i++) {
		buf[i] = twi_read(i<sizeof(buf)-1);
	}
	twi_stop();

	MAG_ORIENTATION(buf[0]<<8 | buf[1],
			buf[4]<<8 | buf[5],
			buf[2]<<8 | buf[3]);

	float m_x = mag_data[M_X]*MAG_SCALE_FACTOR_13;
	float m_y = mag_data[M_Y]*MAG_SCALE_FACTOR_13;
	float m_z = mag_data[M_Z]*MAG_SCALE_FACTOR_13;

#ifdef USE_ACC
	float acc_data[3];
	acc_get_scaled_data(acc_data);
	float heading = _atan2( acc_data[0] * m_z - acc_data[2] * m_x , acc_data[2] * m_y - acc_data[1] * acc_data[2] );
#else
	/* calculate compass bearing in deci-degrees */
	float heading = atan2(m_y, m_x);
#endif
	mag_bearing = heading * 1800.0f/M_PI;
	while (mag_bearing < 0) {
		mag_bearing += 3600;
	}
}

int16_t mag_heading(void) {
	return mag_bearing;
}

void mag_dump(void) {
#ifdef ENABLE_DEBUG_SERIAL_DUMP
	serial_write_str("MAG: ");
	for (uint8_t i=0; i<3; i++) {
		serial_write_int(mag_data[i]);
		serial_write(' ');
	}
	serial_write_int( mag_heading() );
	serial_write('\n');
#endif
}

#endif
