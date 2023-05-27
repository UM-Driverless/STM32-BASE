/*
 * PWM.cpp
 *
 *  Created on: 13 may. 2023
 *      Author: alvar
 */

#include "PWM.h"

PWM::PWM(TIM_HandleTypeDef* timer, uint16_t TIMchannel) {

	this->timer = timer;
	this->TIMchannel = TIMchannel;
	this->duty_cycle = 0;
	HAL_TIM_PWM_Start(timer, TIMchannel);
	this->Arr = __HAL_TIM_GET_AUTORELOAD(timer);
	__HAL_TIM_SET_COMPARE(timer, TIMchannel, 0);


}

void PWM::setDutyCycle(uint16_t duty) {
	__HAL_TIM_SET_COMPARE(timer, TIMchannel, duty);
}
uint16_t PWM::getDutyCycle() {
	return __HAL_TIM_GET_COMPARE(timer, TIMchannel);

}

void PWM::setDutyCycle_8bitScaled(uint8_t prct) {
	uint16_t duty = (Arr/255)*prct;
	__HAL_TIM_SET_COMPARE(timer, TIMchannel, duty);
}

uint8_t PWM::getDutyCycle_8bitScaled() {
	uint16_t duty = __HAL_TIM_GET_COMPARE(timer, TIMchannel);
	return (255/Arr)*duty;

}

PWM::~PWM() {
	// TODO Auto-generated destructor stub
}

