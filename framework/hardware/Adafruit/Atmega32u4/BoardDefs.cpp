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

#include <Wiring.h>

void boardInit(void)
{
  // Initializes main clock used for delay functions, and PWM (fast PWM only)
  Timer0.setMode(0b0011);  // fast PWM
  Timer0.attachInterrupt(INTERRUPT_OVERFLOW, Wiring_Delay_Timer0_overflow);
  Timer0.setClockSource(CLOCK_PRESCALE_64);

  // 16bit timers are initialized for PWM use (phase-correct PWM)
  Timer1.setMode(0b0001);  // phase-correct 8 bit PWM
  Timer1.setClockSource(CLOCK_PRESCALE_64);

  Timer3.setMode(0b0001);  // phase-correct 8 bit PWM
  Timer3.setClockSource(CLOCK_PRESCALE_64);

  // 10bit Timer4 not initialized - not sure which setting to use

  // Start interrupts
  sei();
}
