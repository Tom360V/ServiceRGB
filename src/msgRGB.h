/*
 * msgRGB.h
 *
 *  Created on: 10 jan. 2015
 *      Author: Tommy
 */

#ifndef MSGRGB_H_
#define MSGRGB_H_

#include <stdint.h>
/******************************************************************************
 * TYPESDEFS
 ******************************************************************************/
enum
{
    eACTION_RGB_SRV_SET_COLOR = 0,
    eACTION_RGB_SRV_SET_WHITE,
    eACTION_RGB_SRV_GET_COLOR,
}eACTION_RGB_SRV_t;

enum
{
    eACTION_RGB_CLT_GET_COLOR_RESPONSE = 0,
}eACTION_RGB_CLT_t;
/******************************************************************************
 * STRUCTS
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
