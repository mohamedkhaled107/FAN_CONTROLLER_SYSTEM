/******************************************************************************
 *  File name: main.c
 *  Created on: Oct 8, 2023
 *  Author: Mohamed Khaled
 *******************************************************************************/

#include "adc.h"
#include "lcd.h"
#include "std_types.h"
#include "dcmotor.h"
#include "lm35_sensor.h"

int main(void){
	uint16 temperature=0;
	ADC_ConfigType Config_struct = { INTERNAL_VOLT, PRE_8 }; /* setup of ADC driver */
	ADC_init(&Config_struct);
	LCD_init();
	DCMOTOR_init();

	LCD_moveCursor(0,4);
	LCD_displayString("FAN IS");
	LCD_moveCursor(1,4);
	LCD_displayString("TEMP =");
	LCD_displayStringRowColumn(1,14,"C");
	while(1){
		temperature=LM35_getTemperature();
		LCD_moveCursor(1,10);
		LCD_intgerToString(temperature);
		LCD_displayCharacter(' '); 
		if(temperature < 30){
			DCMOTOR_rotate(STOP,0);
			LCD_moveCursor(0,11);
			LCD_displayString("OFF");
		}
		else if(temperature>=30 && temperature<60){
			DCMOTOR_rotate(CLOCK_WISE,25);
			LCD_moveCursor(0,11);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}
		else if(temperature>=60 && temperature<90){
			DCMOTOR_rotate(CLOCK_WISE,50);
			LCD_moveCursor(0,11);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}
		else if(temperature>=90 && temperature<120){
			DCMOTOR_rotate(CLOCK_WISE,75);
			LCD_moveCursor(0,11);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}
		else if(temperature>=120){
			DCMOTOR_rotate(CLOCK_WISE,100);
			LCD_moveCursor(0,11);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}
	}
	return 0;
}
