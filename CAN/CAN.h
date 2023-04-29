/*
 * CAN.h
 *
 *  Created on: Apr 29, 2023
 *      Author: alvar
 */

#ifndef SRC_CAN_H_
#define SRC_CAN_H_

class CAN {
	private:
		CAN_HandleTypeDef can;
		CAN_FilterTypeDef canfilterconfig;
	public:
		CAN(CAN_HandleTypeDef can, CAN_FilterTypeDef canfilterconfig){};
		void RxMsgInterrupt();
		void TxMessage(uint8_t MsgID, uint8_t MsgData[]);

};
#endif /* SRC_CAN_H_ */
