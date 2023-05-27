/*
 * PWM.h
 *
 *  Created on: 13 may. 2023
 *      Author: alvar
 */

#ifndef SRC_PWM_H_
#define SRC_PWM_H_
#include "stm32f1xx.h"

class PWM {
private:
	TIM_HandleTypeDef* timer;
	uint16_t TIMchannel;
	uint16_t duty_cycle;
	uint16_t Arr;

public:
	PWM(TIM_HandleTypeDef* timer, uint16_t TIMchannel);
	void setDutyCycle(uint16_t duty); //Duty cycle directo
	uint16_t getDutyCycle();
	void setDutyCycle_8bitScaled(uint8_t prct);
	uint8_t getDutyCycle_8bitScaled();


	virtual ~PWM();
};

#endif /* SRC_PWM_H_ */
