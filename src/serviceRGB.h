/*
 * msgRGB.h
 *
 *  Created on: 10 jan. 2015
 *      Author: Tommy
 */

#ifndef MSGRGB_H_
#define MSGRGB_H_

#include <stdint.h>
#include "ServiceDispatcher.h"
#include "ServiceDispatcherQueue.h"

/******************************************************************************
 * TYPEDEFS SERVER
 ******************************************************************************/
void RGBsrv_HandleSetColour (void *pData);
void RGBsrv_HandleSetWhite  (void *pData);
void RGBsrv_HandleGetColour (void *pData);

typedef enum
{
    eACTION_RGB_SRV_SET_COLOR = 0,
    eACTION_RGB_SRV_SET_WHITE,
    eACTION_RGB_SRV_GET_COLOR,
}eACTION_RGB_SRV_t;

static const RemoteFunctionItem_t msgList_msgRGBServer[] =
{
    {eACTION_RGB_SRV_SET_COLOR, RGBsrv_HandleSetColour},
    {eACTION_RGB_SRV_SET_WHITE, RGBsrv_HandleSetWhite},
    {eACTION_RGB_SRV_GET_COLOR, RGBsrv_HandleGetColour},
};

/******************************************************************************
 * TYPEDEFS CLIENT
 ******************************************************************************/
void RGBclt_HandleGetColor_Response (void *pData);

typedef enum
{
    eACTION_RGB_CLT_GET_COLOR_RESPONSE = 0,
}eACTION_RGB_CLT_t;

static const RemoteFunctionItem_t actions_RGBClient[] =
{
    {eACTION_RGB_CLT_GET_COLOR_RESPONSE,    RGBclt_HandleGetColor_Response},
};

/******************************************************************************
 * TYPEDEFS SHARED DATA TYPES
 ******************************************************************************/
typedef struct
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
}msgRGB_SetRGB_t;

typedef struct
{
    uint8_t white;
}msgRGB_SetWhite_t;

#endif /* MSGRGB_H_ */
