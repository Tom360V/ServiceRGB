/*
 * msgRGBServer.c
 *
 *  Created on: Oct 14, 2015
 *      Author: tom
 */

#include <stdio.h>
#include "serviceRGB.h"
#include "serviceRGBServer.h"
#include "ServiceDispatcherQueue.h"
//#include "log.h"

/******************************************************************************
 * PRIVATE STRUCTS
 ******************************************************************************/
//static char myName[] = "MsgRgbSrv";

msgRGBServer_fpHandles_t *fpMsgRgbSrvHandles = NULL;
msgRGB_SetRGB_t myColor = {'r','g','b'};
uint8_t myLampId = 0;
    
/******************************************************************************
 * PRIVATE FUNCTIONS
 ******************************************************************************/

void RGBsrv_HandleSetColour(void *pData)
{
    msgRGB_SetRGB_t * newColor = (msgRGB_SetRGB_t *)pData;
//    LOG(myName, eLOG_Info, "HandleSetColour: %d, %d, %d",newColor->red, newColor->green, newColor->blue);


    LivingColors_turnLampOnRGB(myLampId, newColor->red, newColor->green, newColor->blue);


/*    myColor = *newColor;
    if(fpMsgRgbSrvHandles != 0)
    {
        fpMsgRgbSrvHandles->setRGB(newColor->red, newColor->green, newColor->blue);
    }*/
}

uint8_t ascii2Hex(uint8_t v)
{
    uint8_t x = 0;
    if(v >= 'a')
    {
        x = v - 'a' + 10;
    }
    else if(v >= 'A')
    {
        x = v - 'A' + 10;
    }
    else if(v >= '0')
    {
        x = v - '0';
    }
    return x;
}

uint8_t asciiHex2int(uint8_t *v)
{
    uint8_t value;
    value = ascii2Hex(*v)<<4;
    v++;
    value |= ascii2Hex(*v);
    return value;
}

void RGBsrv_HandleSetColourHex(void *pData)
{
    typedef struct
    {
        uint8_t hash;
        uint8_t r[2];
        uint8_t g[2];
        uint8_t b[2];
    }rgbHex;
    rgbHex *newColor = (msgRGB_SetRGB_t *)pData;


    LivingColors_turnLampOnRGB(myLampId, asciiHex2int(&newColor->r), asciiHex2int(&newColor->g), asciiHex2int(&newColor->b));
}

void RGBsrv_HandleSetWhite(void *pData)
{
    msgRGB_SetWhite_t * newWhite = (msgRGB_SetWhite_t *)pData;
//    LOG(myName, eLOG_Info, "HandleSetWhite: %d",newWhite->white);

    if(fpMsgRgbSrvHandles != 0)
    {
        fpMsgRgbSrvHandles->setWhite(newWhite->white);
    }
}

void RGBsrv_HandleGetColour(void *pData)
{
//    LOG(myName, eLOG_Info, "HandleGetColour: %d, %d, %d",myColor->red, myColor->green, myColor->blue);

    SDQ_AddToSendQueue(eTOPIC_RGB_CLIENT, eACTION_RGB_CLT_GET_COLOR_RESPONSE, (uint8_t*)&myColor, sizeof(myColor), NULL);
}

/******************************************************************************
 * INTERFACE FUNCTIONS
 ******************************************************************************/

void S_RGBServer_Init(fpServiceSubscriber_t fpSubscribe)
{
    unsigned char myLamp[9] = { 0x5B, 0xBF, 0xD5, 0xBA, 0x56, 0x26, 0x67, 0xDB, 0x11 }; //Lamp Tom!
#ifdef LIVING_COLORS
    LivingColors_init();
    LivingColors_clearLamps();
    LivingColors_addLamp(myLamp);

    LivingColors_turnLampOnRGB(myLampId, 255/*RED*/, 0 /*GREEN*/, 0/*BLUE*/);
#else
    
#endif




    fpSubscribe((RemoteFunctionItem_t*)msgList_msgRGBServer, sizeof(msgList_msgRGBServer)/sizeof(RemoteFunctionItem_t), eTOPIC_RGB_SERVER, "rgbServer");
}

void S_RGBServer_SetCallbacks(msgRGBServer_fpHandles_t *handles)
{
    fpMsgRgbSrvHandles = handles;
}
