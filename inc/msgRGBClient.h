/*
 * msgRGBClient.h
 *
 *  Created on: 10 jan. 2015
 *      Author: Tommy
 */

#ifndef MSGRGBCLIENT_H_
#define MSGRGBCLIENT_H_

#include "ServiceDispatcher.h"

/******************************************************************************
 * PUBLIC FUNCTIONS
 ******************************************************************************/
void msgRGBClient_Init(fpServiceSubscriber_t fpSubscriber);
void msgRGBClient_SetColor(uint8_t red, uint8_t green, uint8_t blue);
void msgRGBClient_GetColor();
void msgRGBClient_SetWhite(uint8_t white);
//void msgRGBClient_GetState(uint8_t *state);

#endif /* MSGRGBCLIENT_H_ */
