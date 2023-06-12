/*
 * Servo.cpp
 *
 *  Created on: 13 may. 2023
 *      Author: alvar
 */

#include "Servo.h"

/*
	Ancho de pulso minimo y maximo
	Es necesario ajsutar estos valores al servo que se quiera controlar
	Servo: HS-1005SGT (ASB y Embrague)
*/
#define SERVO_LOWER_LIMIT_PRCNT 4 //Ancho de pulso minimo para el servo - posicion 0
#define SERVO_UPPER_LIMIT_PRCNT 13 //Ancho de pulso máximo - posicion tope

Servo::Servo(TIM_HandleTypeDef* timer, uint16_t TIMchannel) {

	this->timer = timer;
	this->TIMchannel = TIMchannel;
	this->pos = 0;
	HAL_TIM_PWM_Start(timer, TIMchannel);
	this->Arr = __HAL_TIM_GET_AUTORELOAD(timer);
	__HAL_TIM_SET_COMPARE(timer, TIMchannel, 0);


}

/*
	setServoPosition()
	Recibe un numero de 8 bits (0 - 255)
	Ajusta la posicion del servo siendo 0 la posicion mas baja y 255 la mas alta
	Nota: si el servo tiene mas rango de movimiento ej: 360 seria conveniente aumentar la resolucion
*/

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

