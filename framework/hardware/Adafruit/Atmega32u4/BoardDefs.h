/* $Id$
||
|| @author         Yann Dirson <ydirson@free.fr>
|| @url            http://wiring.org.co/
||
|| @description
|| | Board Specific Definitions for:
|| |   Adafruit Atmega32u4 Breakout+ board.
|| |   (Atmel AVR 8 bit microcontroller core)
|| #
||
|| @license Please see cores/Common/License.txt.
||
*/

#ifndef WBOARDDEFS_H
#define WBOARDDEFS_H

#include "WConstants.h"

#define TOTAL_PINS              30
#define FIRST_ANALOG_PIN        (A0)
// there is a numbering hole, avoid libs to trip over it
#define TOTAL_ANALOG_PINS       2

#define LAST_ANALOG_PIN         (A13)
#define ANALOG_PIN_EXISTS(p)		     \
  (((p) >= FIRST_ANALOG_PIN && (p) <= A1) || \
   ((p) >= A4 && (p) <= LAST_ANALOG_PIN))

#define WLED                    (pinE6)

// How many ports are on this device
#define WIRING_PORTS 5

/*************************************************************
 * Prototypes
 *************************************************************/

void boardInit(void);

/*************************************************************
 * Pin locations - constants
 *************************************************************/

// FIXME

/* 0 = Vcc */
const static uint8_t pinE6 = 1;
const static uint8_t pinB0 = 2;
const static uint8_t pinB1 = 3;
const static uint8_t pinB2 = 4;
const static uint8_t pinB3 = 5;
const static uint8_t pinD0 = 6;
const static uint8_t pinD1 = 7;
const static uint8_t pinD2 = 8;
const static uint8_t pinD3 = 9;
const static uint8_t pinD4 = 10;
const static uint8_t pinD5 = 11;
const static uint8_t pinD6 = 12;
const static uint8_t pinD7 = 13;
/* 14 = GND */
/* 15 = GND */
const static uint8_t pinB4 = 16;
const static uint8_t pinB5 = 17;
const static uint8_t pinB6 = 18;
const static uint8_t pinB7 = 19;
const static uint8_t pinC6 = 20;
const static uint8_t pinC7 = 21;
const static uint8_t pinF7 = 22;
const static uint8_t pinF6 = 23;
const static uint8_t pinF5 = 24;
const static uint8_t pinF4 = 25;
const static uint8_t pinF1 = 26;
const static uint8_t pinF0 = 27;
/* 28 = AREF */
/* 29 = Vcc */

// SPI port
#define SS   (pinB0)
#define MOSI (pinB2)
#define MISO (pinB3)
#define SCK  (pinB1)

// TWI port
#define SCL  (pinD0)
#define SDA  (pinD1)

// Analog input pins
const static uint8_t A0 = 0; //   pinF0
const static uint8_t A1 = 1;
/* There are no A2/A3!
const static uint8_t A2 = 2;
const static uint8_t A3 = 3;
*/
const static uint8_t A4 = 4;
const static uint8_t A5 = 5;
const static uint8_t A6 = 6;
const static uint8_t A7 = 7; //   pinF7

const static uint8_t A8 = 8; //   pinD4
const static uint8_t A9 = 9; //   pinD6
const static uint8_t A10 = 10; // pinD7
const static uint8_t A11 = 11; // pinB4
const static uint8_t A12 = 12; // pinB5
const static uint8_t A13 = 13; // pinB6

// Hardware Serial port pins
#define RX1 (pinD2)
#define TX1 (pinD3)

/*************************************************************
 * Pin to register mapping macros
 *************************************************************/

#define digitalPinToPortReg(PIN) \
	( ((PIN) == 1)                  ? &PORTE : \
	( ((PIN) >= 2  && (PIN) <= 5)   ? &PORTB : \
	( ((PIN) >= 6  && (PIN) <= 13)  ? &PORTD : \
	( ((PIN) >= 16	&& (PIN) <= 19) ? &PORTB : \
	( ((PIN) >= 20	&& (PIN) <= 21) ? &PORTC : \
	( ((PIN) >= 22	&& (PIN) <= 27) ? &PORTF : NOT_A_REG))))))

#define digitalPinToBit(PIN) \
	( ((PIN) == 1)                  ? ((PIN + 5)) : \
	( ((PIN) >= 2  && (PIN) <= 5)   ? ((PIN - 2)) :	\
	( ((PIN) >= 6  && (PIN) <= 13)  ? ((PIN - 6)) :	\
	( ((PIN) >= 16	&& (PIN) <= 19) ? ((PIN - 12)) : \
	( ((PIN) >= 20	&& (PIN) <= 21) ? ((PIN - 14)) : \
	( ((PIN) >= 22	&& (PIN) <= 25) ? ((29 - PIN)) : \
	( ((PIN) >= 26	&& (PIN) <= 27) ? ((27 - PIN)) : 0)))))))

#define digitalPinToBitMask(PIN) (1 << (digitalPinToBit(PIN)))

#define digitalPinToPort(PIN) \
	( ((PIN) == 1)                  ? 3 : \
	( ((PIN) >= 2  && (PIN) <= 5)   ? 0 : \
	( ((PIN) >= 6  && (PIN) <= 13)  ? 2 : \
	( ((PIN) >= 16	&& (PIN) <= 19) ? 0 : \
	( ((PIN) >= 20	&& (PIN) <= 21) ? 1 : \
	( ((PIN) >= 22	&& (PIN) <= 27) ? 4 : NOT_A_REG))))))

#define digitalPinToTimer(PIN) \
        ( ((PIN) == pinB7) ? TIMER0A : \
        ( ((PIN) == pinD0) ? TIMER0B : \
	( ((PIN) == pinB5) ? TIMER1A : \
        ( ((PIN) == pinB6) ? TIMER1B : \
        ( ((PIN) == pinC6) ? TIMER3A : \
	NOT_A_TIMER)))))

#if 0
// FIXME: those need TIMER4 init
        ( ((PIN) == pinC7) ? TIMER4A : \
	( ((PIN) == pinD7) ? TIMER4D : \

#endif

#define portOutputRegister(PORT) \
        ( ((PORT) == 0 ) ? &PORTB : \
        ( ((PORT) == 1 ) ? &PORTC : \
        ( ((PORT) == 2 ) ? &PORTD : \
        ( ((PORT) == 3 ) ? &PORTE : \
        ( ((PORT) == 4 ) ? &PORTF : NOT_A_REG)))))

#define portInputRegister(PORT) \
        ( ((PORT) == 0 ) ? &PINB : \
        ( ((PORT) == 1 ) ? &PINC : \
        ( ((PORT) == 2 ) ? &PIND : \
        ( ((PORT) == 3 ) ? &PINE : \
        ( ((PORT) == 4 ) ? &PINF : NOT_A_REG)))))

#define portModeRegister(PORT) \
        ( ((PORT) == 0 ) ? &DDRB : \
        ( ((PORT) == 1 ) ? &DDRC : \
        ( ((PORT) == 2 ) ? &DDRD : \
        ( ((PORT) == 3 ) ? &DDRE : \
        ( ((PORT) == 4 ) ? &DDRF : NOT_A_REG)))))

// FIXME
#define pinToInterrupt(PIN) \
	(-1)

/*************************************************************
 * Timer prescale factors
 *************************************************************/

#define TIMER0PRESCALEFACTOR 64

#endif
// BOARDDEFS_H
