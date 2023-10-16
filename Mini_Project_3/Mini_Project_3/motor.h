/*
 * motor.h
 *
 *  Created on: 28 May 2022
 *      Author: Omar
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "std_types.h"

enum DcMotor_State{
	stop,clockwise,antiClockwise
}state;

extern enum DcMotor_State state;
void DcMotor_init(void);
void DcMotor_Rotate(enum DcMotor_State state, uint8 speed);
void PWM_INIT(uint8 speed);

#endif /* MOTOR_H_ */
