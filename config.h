/*** Funkenschlag configuration file ***/

// use TWI?
//#define ENABLE_TWI

/* ADC configuration */

// enable ADC4 and ADC5 - cannot be used in conjunction with TWI/I²c!
//#define USE_ADC4_ADC5

// enable PCF 8159 ADC via TWI
//#define USE_TWI_ADC

/* Datenschlag configuration */

#define DS_RETRANSMITS 0

// when defined, switch changes cancel all other transissions
//#define DS_BULLY_UPDATE

// transmit switches 1, 2 and 3 via data channel as AUX2-AUX4
#define DS_SEND_AUX_SWITCHES {-1, 1, 2, 3}

// transmit gimbal data
//#define DS_SEND_GIMBAL_ANGLE

// read gimbal angle from ADC input
//#define DS_GIMBAL_ADC 5

// transmit reference heading
//#define DS_SEND_MAG_HEADING

//read headfree orientation from ADC input
//#define DS_HEADING_ADC 5
