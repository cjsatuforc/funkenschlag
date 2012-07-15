/*** Funkenschlag configuration file ***/

// enable serial output?
//#define ENABLE_SERIAL

// use TWI?
//#define ENABLE_TWI

// use custom TWI bitrate?
//#define TWI_BITRATE 100000UL

/* ADC configuration */

// enable ADC4 and ADC5 - cannot be used in conjunction with TWI/I²c!
//#define USE_ADC4_ADC5

// enable PCF 8159 ADC via TWI
//#define USE_TWI_ADC

// enable I²C compass HMC5883
//#define USE_MAG

// change orientation of compass sensor
//#define MAG_ORIENTATION(X, Y, Z)  {mag_data[M_X]  = -(X); mag_data[M_Y]  = (Y); mag_data[M_Z]  = (Z);}

// use I²C LCD (ST7032i)
//#define USE_LCD

// who LCD splash screen on startup
//#define LCD_SPLASH_SCREEN

// show channel status on LCD
//#define LCD_SHOW_CHANNELS
// OR: show crosshairs of stick positions
//#define LCD_SHOW_CROSSHAIRS
// explicitely define input sources for crosshairs
//#define LCD_CROSSHAIR_INPUTS { {channel_source[3], channel_source[2]}, {channel_source[0], channel_source[1]} }
// display bargraphs alongside the crosshairs
//#define LCD_CROSSHAIR_BAR_RIGHT channel_source[6]
//#define LCD_CROSSHAIR_BAR_LEFT  channel_source[7]

// show timer on LCD
//#define LCD_SHOW_TIMER
// show status of Datenschlag switches
//#define LCD_SHOW_DS_SWITCHES
// show magnetic compass heading
//#define LCD_SHOW_MAG
// display battery warning on top of LCD
//#define LCD_SHOW_BATTERY_WARNING

/* Datenschlag configuration */

#define DS_RETRANSMITS 0

// when defined, switch changes cancel all other transissions
//#define DS_BULLY_UPDATE

// transmit switches 1, 2 and 3 via data channel as AUX2-AUX4 (up to 8 inputs can be specified, 0 disables the AUX channel control)
//#define DS_SEND_AUX_SWITCHES {0, SRC_ID(SRC_SW, 1), SRC_ID(SRC_SW, 2), SRC_ID(SRC_SW, 3)}

// transmit gimbal data
//#define DS_SEND_GIMBAL_ANGLE

// read gimbal angle from input
//#define DS_GIMBAL_INPUT SRC_ID(SRC_TWI_ADC, 1)

// transmit reference heading
//#define DS_SEND_MAG_HEADING

//read headfree orientation from input
//#define DS_HEADING_INPUT SRC_ID(SRC_TWI_ADC, 0)

/* external controllers */
// enable the use of Wii Nunchuk? (requires TWI)
//#define USE_NUNCHUK
// angle at which the control is at maximum
//#define NUNCHUK_CTRL_ANGLE 50


/* debugging */
// enable data dump methods
//#define ENABLE_DEBUG_SERIAL_DUMP
