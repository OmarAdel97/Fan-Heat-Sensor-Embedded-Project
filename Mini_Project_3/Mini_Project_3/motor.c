/*
 * motor.c
 *
 *  Created on: 28 May 2022
 *      Author: Omar
 */

#include "motor.h"
#include "gpio.h"
#include "avr/io.h" /* To use the IO Ports Registers */
#include "common_macros.h" /* To use the macros like SET_BIT */

void PWM_INIT(uint8 speed){
	uint8 dutyCycle;
	switch(speed){
	case 25: dutyCycle = 64; break;
	case 50: dutyCycle = 128; break;
	case 75: dutyCycle = 192; break;
	case 100: dutyCycle = 255; break;
	default : dutyCycle = 0; break;
	}
	TCCR0 = (1<<WGM00) | (1<<WGM01)| (1<<COM01)| (1<<CS01);
	TCNT0 = 0;
	OCR0 = dutyCycle;
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);

}
void DcMotor_init(void){
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
	state = stop;
}

void DcMotor_Rotate(enum DcMotor_State currentState, uint8 speed){
	state = currentState;
	switch(currentState){
	case stop:GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
			  GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
			  break;

	case clockwise:GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
				   GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_HIGH);
				   break;

	case antiClockwise:GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
					   GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
					   break;
	default: break;
	}
/*#if(currentState == stop)
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
#elif(currentState == antiClockwise)
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);

#elif(currentState == clockwise)
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_HIGH);
#endif*/

PWM_INIT(speed);
}

