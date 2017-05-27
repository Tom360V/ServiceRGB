/*
 * msgRGBClient.c
 *
 *  Created on: 10 jan. 2015
 *      Author: Tommy
 */


#include "serviceRGB.h"
#include "serviceRGBClient.h"

/******************************************************************************
 * PRIVATE FUNCTIONS
 ******************************************************************************/
void RGBclt_HandleGetColor_Response(void *pData)
{
    msgRGB_SetRGB_t *clientColor = (msgRGB_SetRGB_t *)pData;
    (void)pData;
}

/******************************************************************************
 * PUBLIC FUNCTIONS
 ******************************************************************************/
void S_RGBClient_Init(fpServiceSubscriber_t fpSubscriber)
{
    fpSubscriber((RemoteFunctionItem_t*)actions_RGBClient, sizeof(actions_RGBClient)/sizeof(RemoteFunctionItem_t), eTOPIC_RGB_CLIENT, "rgbClient\0");
}

void S_RGBClient_SetColor(uint8_t red, uint8_t green, uint8_t blue)
{
    msgRGB_SetRGB_t newColor = {red, green, blue};
    SDQ_AddToSendQueue(eTOPIC_RGB_SERVER, eACTION_RGB_SRV_SET_COLOR, (uint8_t *)&newColor, sizeof(newColor), NULL);
}

void S_RGBClient_GetColor()
{
    SDQ_AddToSendQueue(eTOPIC_RGB_SERVER, eACTION_RGB_SRV_GET_COLOR, 0, 0, NULL);
}

void S_RGBClient_SetWhite(uint8_t white)
{
    msgRGB_SetWhite_t newWhite = {white};
    SDQ_AddToSendQueue(eTOPIC_RGB_SERVER, eACTION_RGB_SRV_SET_WHITE, (uint8_t *)&newWhite, sizeof(newWhite), NULL);
}
