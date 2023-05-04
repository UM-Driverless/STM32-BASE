/*
 * Messages.h
 *
 *  Created on: 4 may. 2023
 *      Author: alvar
 */

#ifndef SRC_MESSAGES_H_
#define SRC_MESSAGES_H_



//CAN MESSAGES
#define DV_SYSTEM_STATUS            0x500
#define DV_DRIVING_DYNAMICS_1       0x501
#define DV_DRIVING_DYNAMICS_2       0x502
#define TRAJECTORY_ACT              0x320
//ASB
#define ASB_ANALOG                  0x360
#define ASB_SIGNALS                 0x361
#define ASB_STATE                   0x362
//PMC
#define PMC_STATE                   0x347
//STEERING WHEELL
#define STEER_WH_CONT               0x412
//ETC
#define ETC_SIGNAL                  0x330
#define ETC_STATE                   0x331

#endif /* SRC_MESSAGES_H_ */
