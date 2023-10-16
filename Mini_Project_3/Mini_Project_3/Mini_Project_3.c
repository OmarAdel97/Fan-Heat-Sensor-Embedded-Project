/*
 ================================================================================================
 Name        : Mini_Project_3.c
 Author      : Omar Adel
 Description : FAN CONTROL
 Date        : 28/05/2022
 ================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "motor.h"


volatile uint8 tempValue ;
int main(void){
	ADC_ConfigType configure = {Internal, F_CPU_8};
	ADC_init((const ADC_ConfigType*)&configure);
	LCD_init();
	DcMotor_init();




	LCD_displayStringRowColumn(1, 2, "Temp = ");
	LCD_displayStringRowColumn(1, 12, "C");
	while(1){
		tempValue = LM35_getTemperature();

if(tempValue<30)
		DcMotor_Rotate(stop, 0);
else if(tempValue>=30 && tempValue<60)
		DcMotor_Rotate(clockwise, 25);
else if(tempValue>=60 && tempValue<90)
		DcMotor_Rotate(clockwise, 50);
else if(tempValue>=90 && tempValue<120)
		DcMotor_Rotate(clockwise, 75);
else if(tempValue>=120)
		DcMotor_Rotate(clockwise, 100);

	/* DISPLAY*/
		LCD_moveCursor(0,3);
		if(state == stop){
			LCD_displayStringRowColumn(0, 3, "FAN is OFF");
		}else{
			LCD_displayStringRowColumn(0, 3, "FAN is ON ");
		}
		/* Display the temperature value every time at same position */
		LCD_moveCursor(1,9);
		if(tempValue >= 100)
		{
			LCD_intgerToString(tempValue);
		}
		else
		{
			LCD_intgerToString(tempValue);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
	}

}
