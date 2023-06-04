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
	uint8_t getServoPosition(uint8_t pos);
	uint16_t getDutyCycle();
	void setDutyCycle_8bitScaled(uint8_t prct);
	void setServoPosition(uint8_t pos);
	uint8_t getDutyCycle_8bitScaled();


	virtual ~Servo();
};

#endif /* SRC_SERVO_H_ */
