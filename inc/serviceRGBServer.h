/*
 * msgRGBServer.h
 *
 *  Created on: Oct 14, 2015
 *      Author: tom
 */

#ifndef MSGRGBSERVER_H_
#define MSGRGBSERVER_H_

#include "ServiceDispatcher.h"

/******************************************************************************
 * EXTERNAL TYPES
 ******************************************************************************/
typedef void(*msgRGBServer_fpHandleSetWhite_t)(uint8_t white);
typedef void(*msgRGBServer_fpHandleSetRGB_t)(uint8_t id, uint8_t R, uint8_t G, uint8_t B);

typedef struct
{
    msgRGBServer_fpHandleSetWhite_t setWhite;
    msgRGBServer_fpHandleSetRGB_t setRGB;
} msgRGBServer_fpHandles_t;

/******************************************************************************
 * INTERFACE FUNCTIONS
 ******************************************************************************/
void S_RGBServer_Init(fpServiceSubscriber_t fpAddList);
void S_RGBServer_SetCallbacks(msgRGBServer_fpHandles_t *handles);

#endif /* MSGRGBSERVER_H_ */
