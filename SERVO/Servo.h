/*
 * PWM.h
 *
 *  Created on: 13 may. 2023
 *      Author: alvar
 */

#ifndef SRC_SERVO_H_
#define SRC_SERVO_H_
#include "stm32f1xx.h"

class Servo {
private:
	TIM_HandleTypeDef* timer;
	uint16_t TIMchannel;
	uint8_t pos;
	uint16_t Arr;


public:
	Servo(TIM_HandleTypeDef* timer, uint16_t TIMchannel);
	uint8_t getServoPosition();
	void setServoPosition(uint8_t pos);


	virtual ~Servo();
};

#endif /* SRC_SERVO_H_ */
