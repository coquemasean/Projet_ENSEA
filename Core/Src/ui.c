/*
 * ui.c
 *
 *  Created on: Nov 21, 2021
 *      Author: sydxrey
 *
 *
 *      LCD and touchscreen management for project User Interface.
 */

#include <ui.h>
#include <math.h>
#include <audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "bsp/disco_lcd.h"
#include "bsp/disco_ts.h"
#include "bsp/disco_base.h"
#include "arm_math.h"

//extern

extern double inputLevelLavr;
extern double inputLevelRavr;
extern float FFTInput[];
extern float FFTOutput[];
extern float FFTOutputMag[];

#define FFTLength 256
int delayMs = 0;
int delayFeed = 0;
int volume = 50;
float depth = 0.5;
int time = 0;

/**
 * Display basic UI information.
 */
void uiDisplayBasic(void) {

	LCD_Clear(LCD_COLOR_WHITE);

	LCD_SetStrokeColor(LCD_COLOR_BLACK);
	LCD_SetBackColor(LCD_COLOR_WHITE);
	LCD_SetFont(&Font16);
	LCD_DrawString(0, 0, (uint8_t*) "SIA 2021 - RT AUDIO FX", CENTER_MODE, true);

	/* delay range */
	LCD_DrawRect(60,20,360,30);
	/* feedback range */
	LCD_DrawRect(60,80,360,30);
	/* volume range */
	LCD_DrawRect(435,36,30,200);
	/* Init Vol, Delay, Feed */
	LCD_SetFont(&Font12);
	LCD_DrawString(428,15,(uint8_t *) "Volume", LEFT_MODE, true);
	LCD_DrawString(440,245,(uint8_t *) "50 ", LEFT_MODE, true);
	LCD_SetFillColor(LCD_COLOR_RED);
	LCD_FillRect(436,100+36,29,200-100);

	LCD_DrawString(LCD_SCREEN_WIDTH/2,60,(uint8_t *) "0 ms  ", LEFT_MODE, true);
	LCD_DrawString(200,60,(uint8_t *) "Delay", LEFT_MODE, true);
	LCD_DrawString(LCD_SCREEN_WIDTH/2,120,(uint8_t *) "0 %  ", LEFT_MODE, true);
	LCD_DrawString(180,120,(uint8_t *) "Feedback", LEFT_MODE, true);

	LCD_DrawString(10,5,(uint8_t *) "Input", LEFT_MODE, true);
}

/*
 * Display All Params
 */
static void printDelay(uint32_t x){
	char delay_char[10];
	sprintf(delay_char, "%lu ms  ",x);
	uint16_t X = LCD_SCREEN_WIDTH/2;
	uint16_t Y = 60;
	LCD_DrawString(X,Y,(uint8_t *)delay_char, LEFT_MODE, true);
}

static void printFeedback(uint32_t x){
	char feedback_char[10];
	sprintf(feedback_char, "%lu %% ",x);
	uint16_t X = LCD_SCREEN_WIDTH/2;
	uint16_t Y = 120;
	LCD_DrawString(X,Y,(uint8_t *)feedback_char, LEFT_MODE, true);
}

static void printVolume(uint32_t v){
	char volume_char[10];
	sprintf(volume_char, "%lu  ",v);
	uint16_t X = 440;
	uint16_t Y = 245;
	LCD_DrawString(X,Y,(uint8_t *)volume_char, LEFT_MODE, true);
}

static void printDepth(uint32_t d){
	char volume_char[10];
	sprintf(volume_char, "%lu  ",d);
	uint16_t X = 20;
	uint16_t Y = 20;
	LCD_DrawString(X,Y,(uint8_t *)volume_char, LEFT_MODE, true);
}

/*
 * Range for delay value
 */
void uiSliderDelay(){
	TS_StateTypeDef  TS_State;

	TS_GetState(&TS_State);

	/* detect touch event */
	if(TS_State.touchDetected){

				/* Get X and Y position of the touch post calibrated */
				uint16_t xt = TS_State.touchX[0];
				uint16_t yt = TS_State.touchY[0];
				/* Init position and size of elements */
				int x = 60;
				int y = 20;
				int w = 360;
				int h = 30;

				/* If touch is in the delay bar */
				if(xt>x && xt<x+w && yt>y && yt<y+h){
					/* Position x into delay value in ms */
					delayMs=((xt-x)*10)/2;
					/* Display new delay value */
					printDelay((uint32_t) delayMs);

					/* RED Bar for level */
 					LCD_SetFillColor(LCD_COLOR_RED);
					LCD_FillRect(x+1,y+1,xt-x,h-1);
					/* WHITE Bar for update */
					LCD_SetFillColor(LCD_COLOR_WHITE);
					LCD_FillRect(xt,y+1,w+x-xt,h-1);
				}
	}
}

/*
 * Range for feedback value
 */
void uiSliderFeed(){
	TS_StateTypeDef  TS_State;

	TS_GetState(&TS_State);

	if(TS_State.touchDetected){

				/* Get X and Y position of the touch post calibrated */
				uint16_t xt = TS_State.touchX[0];
				uint16_t yt = TS_State.touchY[0];

				int x = 60;
				int y = 80;
				int w = 360;
				int h = 30;

				if(xt>x && xt<x+w && yt>y && yt<y+h){
					/*Convert in feedback value {0:50}% */
					delayFeed=(uint32_t)(((float)(xt-x)/7.2));

					/* Display new feedback value */
					printFeedback(delayFeed);
					/* RED Bar for level */
					LCD_SetFillColor(LCD_COLOR_RED);
					LCD_FillRect(x+1,y+1,xt-x,h-1);
					/* WHITE Bar for update */
					LCD_SetFillColor(LCD_COLOR_WHITE);
					LCD_FillRect(xt,y+1,w+x-xt,h-1);
				}
	}
}
/*
 * Range for volume value
 */
void uiSliderVolume(){
	TS_StateTypeDef  TS_State;

	TS_GetState(&TS_State);

	/* detect touch event */
	if(TS_State.touchDetected){

				/* Get X and Y position of the touch post calibrated */
				uint16_t xt = TS_State.touchX[0];
				uint16_t yt = TS_State.touchY[0];
				/* Init position and size of elements */
				int x = 435;
				int y = 36;
				int w = 30;
				int h = 200;

				/* If touch is in the volume bar */
				if(xt>x && xt<x+w && yt>y && yt<y+h){
					/* Position yt into volume value in % */
					volume = 100-((yt-y))/2;
					/* Display new volume value */
					printVolume((uint32_t) volume);

					/* RED Bar for level */
 					LCD_SetFillColor(LCD_COLOR_RED);
					LCD_FillRect(x+1,yt,w-1,h-yt+y);
					/* WHITE Bar for update */
					LCD_SetFillColor(LCD_COLOR_WHITE);
					LCD_FillRect(x+1,y+1,w-1,yt-y-1);
				}
	}
}

//Range for flanger
void uiSliderFlanger(){
	TS_StateTypeDef  TS_State;

	TS_GetState(&TS_State);

	/* detect touch event */
	if(TS_State.touchDetected){

				/* Get X and Y position of the touch post calibrated */
				uint16_t xt = TS_State.touchX[0];
				uint16_t yt = TS_State.touchY[0];
				/* Init position and size of elements */
				int x = 20;
				int y = 20;
				int w = 30;
				int h = 200;

				/* If touch is in the volume bar */
				if(xt>x && xt<x+w && yt>y && yt<y+h){
					/* Position yt into volume value in % */
					//depth = 100-((yt-y))/2;
					depth = 0.5;
					/* Display new volume value */
					printDepth((uint32_t) depth);

					/* RED Bar for level */
 					LCD_SetFillColor(LCD_COLOR_RED);
					LCD_FillRect(x+1,yt,w-1,h-yt+y);
					/* WHITE Bar for update */
					LCD_SetFillColor(LCD_COLOR_WHITE);
					LCD_FillRect(x+1,y+1,w-1,yt-y-1);
				}
	}
}


/**
 * Displays line or microphones input level on the LCD.
 */
void uiDisplayInputLevel() {

	uint8_t buf[50];

	LCD_SetStrokeColor(LCD_COLOR_BLACK);
	LCD_SetBackColor(LCD_COLOR_WHITE);
	LCD_SetFont(&Font12);

	if (inputLevelLavr > 0) {
		int lvl_db = (int) (20. * log10(inputLevelLavr));
		sprintf((char*) buf, "%d ", lvl_db);
		LCD_DrawString(5, 15, (uint8_t*) buf, LEFT_MODE, true);
	} else
		LCD_DrawString(5, 15, (uint8_t*) "-inf", LEFT_MODE, true);

	if (inputLevelRavr > 0) {
		int lvl_db = (int) (20. * log10(inputLevelRavr));
		sprintf((char*) buf, "%d ", lvl_db);
		LCD_DrawString(30, 15, (uint8_t*) buf, LEFT_MODE, true);
	} else
		LCD_DrawString(30, 15, (uint8_t*) "-inf", LEFT_MODE, true);



}
/**
 * Displays spectrogram.
 */

uint32_t VAL;
void uiDisplaySpectrum() {
	/* sweep reset */
	if(time>360){
		time=0;
	}
	/* sweep init position */
	uint16_t x=time+60;
	uint16_t y=270;
	uint32_t color;

	/* run through mag values */
	for(int i=0;i<(256/2);i++){
		/* Amplitude of frequency "i" */
		VAL = (uint32_t) (FFTOutputMag[i]*255);
		color=(uint32_t) 4278190080+(VAL);

		/* shade of blue */
		LCD_DrawPixelColor(x,y-(i),(uint32_t) color);
		/* tracking bar */
		LCD_DrawPixelColor(x+1,y-(i),(uint32_t) (4278190080+16753920));
	}
	/* new sweep position */
	time=time+1;
}

/**
 * Displays Master VU level.
 */
void uiDisplayMaster() {
	int dbL = (int) (20. * log10(inputLevelLavr));
	int dbR = (int) (20. * log10(inputLevelRavr));

	uiDisplayInputLevel();

	int L = -2*(dbL+60)-100; // augmentation de dynamique pour l'affichage
	int R =	-2*(dbR+60)-100; //

	/* Refresh bar */
	LCD_SetFillColor(LCD_COLOR_WHITE);
	LCD_FillRect(5, 30, 20, (270+L));
	LCD_FillRect(35, 30, 20 , (270+R));
	/* Value bar */
	LCD_SetFillColor(LCD_COLOR_RED);
	LCD_FillRect(5, 270+L, 20, LCD_SCREEN_HEIGHT-(270+L));
	LCD_FillRect(35, 270+R, 20, LCD_SCREEN_HEIGHT-(270+R));
}


