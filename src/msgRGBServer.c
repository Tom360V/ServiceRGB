/*
 * msgRGBServer.c
 *
 *  Created on: Oct 14, 2015
 *      Author: tom
 */

#include <stdio.h>
#include "msgRGB.h"
#include "msgRGBServer.h"
#include "ServiceDispatcherQueue.h"

//#include "log.h"

/******************************************************************************
 * PRIVATE STRUCTS
 ******************************************************************************/
//static char myName[] = "MsgRgbSrv";

msgRGBServer_fpHandles_t *fpMsgRgbSrvHandles = NULL;
msgRGB_SetRGB_t myColor = {7,8,9};
/******************************************************************************
 * PRIVATE FUNCTIONS
 ******************************************************************************/

void HandleSetColour(void *pData)
{
    msgRGB_SetRGB_t * newColor = (msgRGB_SetRGB_t *)pData;
//    LOG(myName, eLOG_Info, "HandleSetColour: %d, %d, %d",newColor->red, newColor->green, newColor->blue);

    myColor = *newColor;
    if(fpMsgRgbSrvHandles != 0)
    {
        fpMsgRgbSrvHandles->setRGB(newColor->red, newColor->green, newColor->blue);
    }
}

void HandleSetWhite(void *pData)
{
    msgRGB_SetWhite_t * newWhite = (msgRGB_SetWhite_t *)pData;
//    LOG(myName, eLOG_Info, "HandleSetWhite: %d",newWhite->white);

    if(fpMsgRgbSrvHandles != 0)
    {
        fpMsgRgbSrvHandles->setWhite(newWhite->white);
    }
}

void HandleGetColour(void *pData)
{
//    LOG(myName, eLOG_Info, "HandleGetColour: %d, %d, %d",myColor->red, myColor->green, myColor->blue);

    SDQ_AddToSendQueue(eTOPIC_RGB_CLIENT, eACTION_RGB_CLT_GET_COLOR_RESPONSE, (uint8_t*)&myColor, sizeof(myColor), NULL);
}

/******************************************************************************
 *
 */
static const RemoteFunctionItem_t msgList_msgRGBServer[] =
{
    {eACTION_RGB_SRV_SET_COLOR, HandleSetColour},
    {eACTION_RGB_SRV_SET_WHITE, HandleSetWhite},
    {eACTION_RGB_SRV_GET_COLOR, HandleGetColour},
};

/******************************************************************************
 * INTERFACE FUNCTIONS
 ******************************************************************************/
void msgRGBServer_Init(fpServiceSubscriber_t fpSubscribe)
{
    fpSubscribe((RemoteFunctionItem_t*)msgList_msgRGBServer, sizeof(msgList_msgRGBServer)/sizeof(RemoteFunctionItem_t), eTOPIC_RGB_SERVER, "rgbServer");
}

void msgRGBServer_SetCallbacks(msgRGBServer_fpHandles_t *handles)
{
    fpMsgRgbSrvHandles = handles;
}
