/*
 * Servo.cpp
 *
 *  Created on: 13 may. 2023
 *      Author: alvar
 */

#include "Servo.h"
#define SERVO_LOWER_LIMIT_PRCNT 4
#define SERVO_UPPER_LIMIT_PRCNT 13
Servo::Servo(TIM_HandleTypeDef* timer, uint16_t TIMchannel) {

	this->timer = timer;
	this->TIMchannel = TIMchannel;
	this->pos = 0;
	HAL_TIM_Servo_Start(timer, TIMchannel);
	this->Arr = __HAL_TIM_GET_AUTORELOAD(timer);
	__HAL_TIM_SET_COMPARE(timer, TIMchannel, 0);


}


void Servo::setServoPosition(uint8_t pos) {
	this->pos = pos;
	uint16_t percent = (pos*(SERVO_UPPER_LIMIT_PRCNT*(Arr/100) - SERVO_LOWER_LIMIT_PRCNT*(Arr/100)) / 255) + 1196;
	__HAL_TIM_SET_COMPARE(timer, TIMchannel, percent);
}

uint8_t Servo::getServoPosition() {
	return pos;
}



Servo::~Servo() {
	// TODO Auto-generated destructor stub
}

