/*
 * msgRGBClient.c
 *
 *  Created on: 10 jan. 2015
 *      Author: Tommy
 */


#include "ServiceDispatcherQueue.h"
#include "msgRGB.h"
#include "msgRGBClient.h"

//static char myName[] = "RGBclient";

/******************************************************************************
 * PRIVATE FUNCTIONS
 ******************************************************************************/
void GetColor_Response(void *pData)
{
    msgRGB_SetRGB_t *clientColor = (msgRGB_SetRGB_t *)pData;
    (void)pData;
}

/******************************************************************************
 *
 ******************************************************************************/
static const RemoteFunctionItem_t actions_RGBClient[] =
{
    {eACTION_RGB_CLT_GET_COLOR_RESPONSE ,GetColor_Response},
};

/******************************************************************************
 * PUBLIC FUNCTIONS
 ******************************************************************************/
void msgRGBClient_Init(fpServiceSubscriber_t fpSubscriber)
{
    fpSubscriber((RemoteFunctionItem_t*)actions_RGBClient, sizeof(actions_RGBClient)/sizeof(RemoteFunctionItem_t), eTOPIC_RGB_CLIENT, "rgbClient");
}

void msgRGBClient_SetColor(uint8_t red, uint8_t green, uint8_t blue)
{
    msgRGB_SetRGB_t newColor = {red, green, blue};
    SDQ_AddToSendQueue(eTOPIC_RGB_SERVER, eACTION_RGB_SRV_SET_COLOR, (uint8_t *)&newColor, sizeof(newColor), NULL);
}

void msgRGBClient_GetColor()
{
    SDQ_AddToSendQueue(eTOPIC_RGB_SERVER, eACTION_RGB_SRV_GET_COLOR, 0, 0, NULL);
}

void msgRGBClient_SetWhite(uint8_t white)
{
    msgRGB_SetWhite_t newWhite = {white};
    SDQ_AddToSendQueue(eTOPIC_RGB_SERVER, eACTION_RGB_SRV_SET_WHITE, (uint8_t *)&newWhite, sizeof(newWhite), NULL);
}
