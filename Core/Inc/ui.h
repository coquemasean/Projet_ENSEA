/*
 * ui.h
 *
 *  Created on: Nov 21, 2021
 *      Author: sydxrey
 */

#ifndef INC_UI_H_
#define INC_UI_H_

#include "bsp/disco_lcd.h"


void uiDisplayBasic(void);
void uiDisplayInputLevel(void);
void uiDisplaySpectrum(void);
void uiSliderDelay(void);
void uiSliderFeed(void);
void uiSliderVolume(void);
void uiDisplayMaster(void);

#endif /* INC_UI_H_ */
