/*
 * CAN.cpp
 *
 *  Created on: Apr 29, 2023
 *      Author: alvar
 */

#include "CAN.h"


CAN::CAN(CAN_HandleTypeDef can, CAN_FilterTypeDef canfilterconfig) {
	this->can = can;
	HAL_CAN_Start(&can);
	this->canfilterconfig = canfilterconfig;

}




void CAN::TxMessage(uint16_t MsgID, uint8_t MsgData[]) {
	CAN_TxHeaderTypeDef TxHeader;
	uint32_t TxMailbox;

	int MsgSize = sizeof(MsgData)/sizeof(uint8_t);
	if (MsgSize > 8 ) throw CANException(CAN_MSG_TOO_BIG);
	if(MsgID > 2048) throw CANException(CAN_ID_TOO_BIG);

	TxHeader.IDE = CAN_ID_EXT;
	TxHeader.StdId = (uint8_t) MsgID;
	TxHeader.ExtId = (uint8_t) MsgID << 8;
	TxHeader.RTR = CAN_RTR_DATA;
	TxHeader.DLC = MsgSize;
	HAL_CAN_AddTxMessage(&can, &TxHeader, MsgData, &TxMailbox);


}


