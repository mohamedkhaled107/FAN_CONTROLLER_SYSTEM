/******************************************************************************
*  Module: ADC
*  File name: adc.h
*  Created on: Oct 9, 2023
*  Author: Mohamed Khaled
*******************************************************************************/
#ifndef ADC_H_
#define ADC_H_
/*******************************************************************************
 *                                  Includes                                   *
 *******************************************************************************/
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum{
	AREF,AVCC,RESERVED,INTERNAL_VOLT
}ADC_RefrenceVoltage;

typedef enum{
	NO_PRE,PRE_2,PRE_4,PRE_8,PRE_16,PRE_32,PRE_64,PRE_128
}ADC_Prescaler;

typedef struct{
	ADC_Prescaler prescaler;
	ADC_RefrenceVoltage ref_volt;
}ADC_ConfigType;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void ADC_init(const ADC_ConfigType *config_ptr);

uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
