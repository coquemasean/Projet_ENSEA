///*
// * test.c
// *
// *  Created on: May 14, 2021
// *      Author: sydxrey
// */
//
//#include <audio.h>
//#include "test.h"
//#include "stm32f7xx_hal.h"
//#include "stdio.h"
//#include "bsp/disco_qspi.h"
//#include "bsp/disco_sdram.h"
//#include "bsp/disco_lcd.h"
//#include "bsp/disco_ts.h"
//#include "bsp/disco_base.h"
//#include "stdlib.h"
//#include "arm_math.h"
//
//
//
//extern UART_HandleTypeDef huart6;
//
//extern const unsigned char logo[9174];
//
//static void testLED();
//static void testPushButton();
//static void testVCP();
//static void testUSART6();
//static void testTouchscreen();
//static void testTouchscreen();
//static void testLCD();
//static void drawBigPixel(uint16_t x, uint16_t y);
//static void drawBiggerPixel(uint16_t x, uint16_t y);
//static void drawButton(int x, int y, int w, int h,uint8_t* text);
//static int isTouch(int x, int y, int w, int h,uint16_t xt, uint16_t yt);
//static void consoleLog(uint16_t x);
//static void testMenu();
//static void testQSPI();
//static void testSDRAM();
//static void testSDRAM_DMA();
//static void testAUDIO();
//static void testCMSIS_DSP();
//static void testFFT();
//static void uiSimple(float32_t * FFTOutput);
//static void     Fill_Buffer (uint8_t *pBuffer, uint32_t uwBufferLength, uint32_t uwOffset);
//static uint8_t  Buffercmp   (uint8_t* pBuffer1, uint8_t* pBuffer2, uint32_t BufferLength);
//static void 	Fill_Buffer32(uint32_t *pBuffer, uint32_t uwBufferLenght, uint32_t uwOffset);
//static uint8_t 	Buffercmp32(uint32_t* pBuffer1, uint32_t* pBuffer2, uint16_t BufferLength);
//
//enum {
//	NONE,
//	TEST_VCP,
//	TEST_LED,
//	TEST_PUSH_BUTTON,
//	TEST_USART6,
//	TEST_TOUCHSCREEN,
//	TEST_QSPI,
//	TEST_SDRAM,
//	TEST_SDRAM_DMA,
//	TEST_LCD,
//	TEST_AUDIO,
//	TEST_CMSIS_DSP,
//	TEST_MENU
//} test_case;
//
//// for testing QSPI and SDRAM:
//#define QSPI_BUFFER_SIZE         ((uint32_t)0x0010)
//#define QSPI_WRITE_READ_ADDR     ((uint32_t)0x0050)
//#define SDRAM_BUFFER_SIZE      ((uint32_t)16)
//
//#ifdef ALLOCATE_TEST_DATA
//	uint8_t qspi_aTxBuffer[QSPI_BUFFER_SIZE];
//	uint8_t qspi_aRxBuffer[QSPI_BUFFER_SIZE];
//	//static uint32_t sdram_aTxBuffer[SDRAM_BUFFER_SIZE];
//	//static uint32_t sdram_aRxBuffer[SDRAM_BUFFER_SIZE];
//	ALIGN_32BYTES (static uint32_t sdram_aTxBuffer[SDRAM_BUFFER_SIZE]);
//	ALIGN_32BYTES (static uint32_t sdram_aRxBuffer[SDRAM_BUFFER_SIZE]);
//#endif
//
//extern __IO uint32_t uwDMA_Transfer_Complete;
//
//// ------------------- public functions --------------------------
//
//void test(){
//
//	testFFT();
//	//testMenu();
//
//	switch (test_case){
//		case NONE:
//			testFFT();
//			break;
//		case TEST_VCP:
//			testVCP();
//			break;
//		case TEST_LED:
//			testLED();
//			break;
//		case TEST_PUSH_BUTTON:
//			testPushButton();
//			break;
//		case TEST_USART6:
//			testUSART6();
//			break;
//		case TEST_TOUCHSCREEN:
//			testTouchscreen();
//			break;
//		case TEST_QSPI:
//			testQSPI();
//			break;
//		case TEST_SDRAM:
//			testSDRAM();
//			break;
//		case TEST_SDRAM_DMA:
//			testSDRAM_DMA();
//			break;
//		case TEST_LCD:
//			testLCD();
//			break;
//		case TEST_AUDIO:
//			testAUDIO();
//			break;
//		case TEST_MENU:
//			testMenu();
//			break;
//		case TEST_CMSIS_DSP:
//			testCMSIS_DSP();
//		}
//
//	while (1){
//
//		LED_Toggle();
//		HAL_Delay(100);
//	}
//}
//
//static void testMenu(){
//	TS_StateTypeDef  TS_State;
//
//	LCD_Clear(LCD_COLOR_WHITE);
//	LCD_SetStrokeColor(LCD_COLOR_RED);
//
//	int btn=0;
//
//	while(test_case==NONE){
//
//			/* Check in polling mode in touch screen the touch status and coordinates */
//			/* if touch occurred                                                      */
//			TS_GetState(&TS_State);
//
//			drawButton(4,1,6,3,(uint8_t*)"paint");
//			drawButton(-4,1,6,3,(uint8_t*)"lcd");
//			drawButton(4,-1,6,3,(uint8_t*)"btn");
//			drawButton(-4,-1,6,3,(uint8_t*)"audio");
//
//			if(TS_State.touchDetected){
//				/* Get X and Y position of the touch post calibrated */
//				uint16_t x = TS_State.touchX[0];
//				uint16_t y = TS_State.touchY[0];
//
//				if(isTouch(4,1,6,3,x,y)){
//					test_case=TEST_TOUCHSCREEN;
//					HAL_Delay(200);
//				}
//				if(isTouch(-4,1,6,3,x,y)){
//					test_case=TEST_LCD;
//					HAL_Delay(200);
//				}
//				if(isTouch(4,-1,6,3,x,y)){
//					test_case=TEST_PUSH_BUTTON;
//					HAL_Delay(200);
//				}
//				if(isTouch(-4,-1,6,3,x,y)){
//					test_case=TEST_AUDIO;
//					HAL_Delay(200);
//				}
//
//				HAL_Delay(100);
//				LED_Toggle();
//			}
//		}
//}
//
//
//
//// ------------------- private functions --------------------------
//
//static void testLED(){
//
//	consoleLog(0);
//
//
//	while(1){
//		HAL_GPIO_TogglePin(GPIOI, LD_GREEN_Pin);
//		HAL_Delay(100);
//	}
//
//
//}
//
//static void testPushButton(){
//
//	while(1){
//		if (PB_GetState()>0) LED_On();
//		else LED_Off();
//		HAL_Delay(100);
//	}
//
//}
//
//static void testVCP(){
//
//	int i=0;
//	while(1){
//
//		printf("%d\n", i++);
//		HAL_Delay(500);
//
//	}
//}
//
///*
// *  PC7     ------> USART6_RX (ard D0)
// *  PC6     ------> USART6_TX (ard D1)
// */
//static void testUSART6(){
//
//	uint8_t v = 0x77;
//
//	while(1){
//
//		HAL_UART_Transmit(&huart6, &v, 1, 100);
//		HAL_Delay(1);
//
//	}
//}
//
//// ========================================================= Test Touchscreen & display ======================================
//
//
//static void testLCD(){
//
//	Point polygon[5] = {{.X=10, .Y=10},{.X=100, .Y=40},{.X=200, .Y=90},{.X=310, .Y=110},{.X=210, .Y=200}};
//
//	LCD_Clear();
//	uint16_t Xpos = LCD_SCREEN_WIDTH/2;
//	uint16_t Ypos = LCD_SCREEN_HEIGHT/2;
//	//uint32_t color = 0xFF000000;
//
//	//LCD_SetFont(&Font8);
//
//	LCD_SetStrokeColor(LCD_COLOR_BLUE);
//	LCD_SetFillColor(LCD_COLOR_RED);
//
//	// 1) test pixels drawing
//	LCD_DrawLine(0,0,100,100);
//	LCD_DrawHLine(10, 20, 80);
//	LCD_DrawVLine(10, 20, 80);
//	LCD_FillRect(200,200,50,50);
//	LCD_DrawRect(200,200,50,50);
//	LCD_FillCircle(300, 150, 20);
//	LCD_DrawCircle(300, 150, 20);
//	LCD_FillPolygon(polygon, 6);
//	LCD_DrawPolygon(polygon, 6);
//	LCD_DrawEllipse(200, 180, 50, 25);
//
//	// 2) test char drawing:
//	LCD_DrawChar(10,20,'D', true);
//	LCD_DrawStringAtLine(5, (uint8_t *)"hello", true);
//	LCD_ClearStringAtLine(5);
//
//	// 3) test bitmap drawing:
//	LCD_DrawBitmap(150, 65, (uint8_t *)logo); // logo takes up a lot of space!
//
//	HAL_Delay(2000);
//	LCD_Clear();
//
//	LCD_SetStrokeColor(LCD_COLOR_GREEN);
//	LCD_DrawString(10, 20, (uint8_t *)"Random Walk on a plane", LEFT_MODE, true);
//
//	LCD_SetStrokeColor(LCD_COLOR_MAGENTA);
//	while(1){
//		Xpos += (rand() % 3) - 1;
//		Ypos += (rand() % 3) - 1;
//		Xpos %= LCD_SCREEN_WIDTH;
//		Ypos %= LCD_SCREEN_HEIGHT;
//		//color = 0xFF000000 | (rand() & 0x00FFFFFF);
//		LCD_DrawPixel(Xpos, Ypos);
//		//LCD_DrawPixel(Xpos, Ypos, LCD_COLOR_RED);
//		//LCD_FillRect(Xpos, Ypos, 5, 5);
//		HAL_Delay(1);
//	}
//
//}
//
//
//static void testTouchscreen(){
//
//	TS_StateTypeDef  TS_State;
//
//	LCD_Clear(LCD_COLOR_WHITE);
//	LCD_SetStrokeColor(LCD_COLOR_RED);
//
//	int size=0;
//	consoleLog(size);
//
//	while(1){
//
//		/* Check in polling mode in touch screen the touch status and coordinates */
//		/* if touch occurred                                                      */
//
//
//		drawButton(2,1,3,2,(uint8_t*)"-");
//		drawButton(-2,1,3,2,(uint8_t*)"+");
//		drawButton(-2,-1,3,2,(uint8_t*)"r");
//
//		if(TS_State.touchDetected){
//
//			/* Get X and Y position of the touch post calibrated */
//			uint16_t x = TS_State.touchX[0];
//			uint16_t y = TS_State.touchY[0];
//			printf("Nb touch detected = %d\n", TS_State.touchDetected);
//
//			printf("1[%d,%d]\n", x, y);
//
//			if(isTouch(2,1,5,3,x,y)){
//				if(size>0){
//					size-=1;
//				}
//				HAL_Delay(200);
//			}
//			if(isTouch(-2,1,5,3,x,y)){
//				if(size<2){
//					size+=1;
//				}
//				HAL_Delay(200);
//			}
//			if(isTouch(-2,-1,3,2,x,y)){
//				LCD_Clear(LCD_COLOR_WHITE);
//				HAL_Delay(200);
//			}
//
//			consoleLog(size);
//
//			if(size==0){
//				LCD_DrawPixel(x, y);
//			}else if(size==1){
//				drawBigPixel(x,y);
//			}else if(size==2){
//				drawBiggerPixel(x,y);
//			}
//
//
//			/* Display 2nd touch detected coordinates if applicable */
//			if (TS_State.touchDetected >= 2){
//
//				printf("2[%d,%d]\n", TS_State.touchX[1], TS_State.touchY[1]);
//				LCD_DrawLine(x, y,  TS_State.touchX[1], TS_State.touchY[1]);
//			}
//
//			HAL_Delay(1);
//			LED_Toggle();
//		}
//	}
//
//}
//
//
//
//static void drawBigPixel(uint16_t x, uint16_t y){
//	LCD_DrawPixel(x, y);
//	LCD_DrawPixel(x+1, y);
//	LCD_DrawPixel(x+1, y+1);
//	LCD_DrawPixel(x, y+1);
//	LCD_DrawPixel(x-1, y+1);
//	LCD_DrawPixel(x-1, y);
//	LCD_DrawPixel(x-1, y-1);
//	LCD_DrawPixel(x, y-1);
//	LCD_DrawPixel(x+1, y-1);
//
//}
//
//
//static void drawBiggerPixel(uint16_t x, uint16_t y){
//	drawBigPixel(x, y);
//	drawBigPixel(x+1, y);
//	drawBigPixel(x+1, y+1);
//	drawBigPixel(x, y+1);
//	drawBigPixel(x-1, y+1);
//	drawBigPixel(x-1, y);
//	drawBigPixel(x-1, y-1);
//	drawBigPixel(x, y-1);
//	drawBigPixel(x+1, y-1);
//}
//
//static void drawButton(int x, int y, int w, int h,uint8_t* text){
//	int xsize=16;
//	int ysize=24;
//	int l = strlen((const char*)text)*xsize;
//
//	if(x<0){
//		x= LCD_SCREEN_WIDTH-((w-x)*xsize);
//	}else{
//		x=x*xsize;
//	}
//	if(y<0){
//		y= LCD_SCREEN_HEIGHT-((h-y)*ysize);
//	}else{
//		y=y*ysize;
//	}
//	w=w*xsize;
//	h=h*ysize;
//	LCD_DrawRect((uint16_t)x,(uint16_t)y,w,h);
//	LCD_DrawRect((uint16_t)x+1,(uint16_t)y+1,w,h);
//	int xs = x+(w-l)/2;
//	int ys = y+(h-ysize)/2;
//
//	LCD_DrawString(xs,ys,(uint8_t *)text, LEFT_MODE, true);
//	//LCD_DrawLine(x,y,x+w,y);
//	//LCD_DrawLine(x,y+h,x+w,y+h);
//	//LCD_DrawLine(x,y,x,y+h);
//	//LCD_DrawLine(x+w,y,x+w,y+h);
//}
//
//static int isTouch(int x, int y, int w, int h,uint16_t xt, uint16_t yt){
//	int xsize=16;
//	int ysize=24;
//
//	if(x<0){
//		x= LCD_SCREEN_WIDTH-((w-x)*xsize);
//	}else{
//		x=x*xsize;
//	}
//	if(y<0){
//		y= LCD_SCREEN_HEIGHT-((h-y)*ysize);
//	}else{
//		y=y*ysize;
//	}
//	w=w*xsize;
//	h=h*ysize;
//	if(xt>x && xt<x+w && yt>y && yt<y+h){
//		return 1;
//	}else{
//		return 0;
//	}
//}
//
//static void consoleLog(uint16_t x){
//	char test[10];
//	sprintf(test, "%d",x);
//	uint16_t X = LCD_SCREEN_WIDTH/2;
//	uint16_t Y = LCD_SCREEN_HEIGHT-24;
//	LCD_DrawString(X,Y,(uint8_t *)test, LEFT_MODE, true);
//}
//
//void testold(){
//
//	test_case = TEST_MENU;
//
//	switch (test_case){
//	case TEST_VCP:
//		testVCP();
//		break;
//	case TEST_LED:
//		testLED();
//		break;
//	case TEST_PUSH_BUTTON:
//		testPushButton();
//		break;
//	case TEST_USART6:
//		testUSART6();
//		break;
//	case TEST_TOUCHSCREEN:
//		testTouchscreen();
//		break;
//	case TEST_QSPI:
//		testQSPI();
//		break;
//	case TEST_SDRAM:
//		testSDRAM();
//		break;
//	case TEST_SDRAM_DMA:
//		testSDRAM_DMA();
//		break;
//	case TEST_LCD:
//		testLCD();
//		break;
//	case TEST_AUDIO:
//		testAUDIO();
//		break;
//	case TEST_MENU:
//		testMenu();
//		break;
//	case TEST_CMSIS_DSP:
//		testCMSIS_DSP();
//	}
//
//
//	while (1){
//
//		LED_Toggle();
//		HAL_Delay(100);
//	}
//}
//
//
//// ========================================================= Test audio ======================================
//
//
//static void testAUDIO(){
//
//	//audioLoop();
//
//}
//
//// ========================================================= Test CMSIS-DSP library ======================================
//
//
//static void testCMSIS_DSP(){
//
//	// cf. https://www.keil.com/pack/doc/CMSIS/DSP/html/index.html
//	float32_t FFT_Input_Q15_f[50];
//	float32_t aFFT_Input_Q15[50];
//	#define FFT_Length  1024
//
//	arm_float_to_q15((float32_t *)&FFT_Input_Q15_f[0], (q15_t *)&aFFT_Input_Q15[0], FFT_Length*2);
//
//}
//
//#define FFTLength 256
//
//arm_rfft_fast_instance_f32 FFTStruct;
//
//
//static void testFFT(){
//	float32_t FFTInput[FFTLength];
//	float32_t FFTOutput[FFTLength];
//	float32_t FFTOutput_mag[FFTLength];
//
//	LCD_Clear(LCD_COLOR_WHITE);
//	LCD_SetStrokeColor(LCD_COLOR_RED);
//
//
//	//init
//	arm_rfft_fast_init_f32(&FFTStruct, FFTLength);
//
//	float mu = (float) 0.5;
//
//	while(1){
//		if(mu<=0){
//			mu = (float) 0.5;
//		}
//		//signal
//		for(int i=0;i<FFTLength;i++){
//				FFTInput[i] = 0.5 + sin(2.0* 3.141592 * mu * i);
//		}
//
//		//calc
//		arm_rfft_fast_f32(&FFTStruct,FFTInput,FFTOutput,0);
//
//		arm_cmplx_mag_f32(FFTInput,FFTOutput_mag,FFTLength/2);
//
//		uiSimple(FFTOutput);
//
//		uint16_t test = mu*1000;
//
//		consoleLog(test);
//		mu-=0.005;
//		HAL_Delay(1000);
//
//	}
//}
//
//static void uiSimple(float32_t * FFTOutput){
//	LCD_Clear(LCD_COLOR_WHITE);
//	uint16_t x=16;
//	uint16_t y;
//	for(int i=0;i<FFTLength;i++){
//			x+=1;
//			y=150-(uint16_t) FFTOutput[i];
//			LCD_DrawPixel(x,y);
//			while(y<150){
//				y+=1;
//				LCD_DrawPixel(x,y);
//			}
//
//		}
//}
//
//
//// ========================================================= Test SDRAM, QSPI ======================================
//
//
//static void testQSPI(){
//
//#ifdef ALLOCATE_TEST_DATA
//	/* Erase QSPI memory */
//	if(DISCO_QSPI_Erase_Block(QSPI_WRITE_READ_ADDR) != HAL_OK){
//		printf("QSPI ERASE: FAILED\n");
//		Error_Handler();
//	}
//	else {
//		printf("QSPI ERASE: OK\n");
//	}
//
//	/* Fill the buffer to write */
//	Fill_Buffer(qspi_aTxBuffer, QSPI_BUFFER_SIZE, 0xD20F);
//
//	/* Write data to the QSPI memory */
//	if(DISCO_QSPI_Write(qspi_aTxBuffer, QSPI_WRITE_READ_ADDR, QSPI_BUFFER_SIZE) != HAL_OK){
//		printf("QSPI WRITE: FAILED\n");
//		Error_Handler();
//	}
//	else {
//		printf("QSPI WRITE: OK\n");
//	}
//
//	/* Read back data from the QSPI memory */
//	if(DISCO_QSPI_Read(qspi_aRxBuffer, QSPI_WRITE_READ_ADDR, QSPI_BUFFER_SIZE) != HAL_OK){
//		printf("QSPI READ: FAILED\n");
//		Error_Handler();
//	}
//	else {
//		printf("QSPI READ: OK\n");
//	}
//
//	/* Checking data integrity */
//	if(Buffercmp(qspi_aRxBuffer, qspi_aTxBuffer, QSPI_BUFFER_SIZE) > 0){
//		printf("QSPI COMPARE: FAILED\n");
//		Error_Handler();
//	}
//	else {
//		printf("QSPI COMPARE: OK\n");
//	}
//#else
//	printf("To activate QSPI test unit, first uncomment #define ALLOCATE_TEST_DATA\n");
//#endif
//}
//
//static void testSDRAM(){
//
//#ifdef ALLOCATE_TEST_DATA
//
//	Fill_Buffer32(sdram_aTxBuffer, SDRAM_BUFFER_SIZE, 0x000186A0); // 0xA244250F);
//
//	if (DISCO_SDRAM_WriteData((SDRAM_WRITE_READ_ADDR + SDRAM_WRITE_READ_ADDR_OFFSET), sdram_aTxBuffer, SDRAM_BUFFER_SIZE) != HAL_OK)
//		Error_Handler();
//	else
//		printf("SDRAM write data ok\n");
//
//	if (DISCO_SDRAM_ReadData(SDRAM_WRITE_READ_ADDR + SDRAM_WRITE_READ_ADDR_OFFSET, sdram_aRxBuffer, SDRAM_BUFFER_SIZE) != HAL_OK)
//		Error_Handler();
//	else
//		printf("SDRAM read data ok\n");
//
//	int i = Buffercmp32(sdram_aTxBuffer, sdram_aRxBuffer, SDRAM_BUFFER_SIZE);
//	if (i > 0){
//		printf("SDRAM buffer compare FAILED at position %ld\n", SDRAM_BUFFER_SIZE-i);
//		Error_Handler();
//	}
//	else
//		printf("SDRAM buffer compare ok\n");
//
//#else
//	printf("To activate SDRAM test unit, first uncomment #define ALLOCATE_TEST_DATA\n");
//#endif
//
//}
//
//static void testSDRAM_DMA(){
//
//#ifdef ALLOCATE_TEST_DATA
//
//	Fill_Buffer32(sdram_aTxBuffer, SDRAM_BUFFER_SIZE, 0x000186A0);
//
//	uwDMA_Transfer_Complete = 0;
//	if (DISCO_SDRAM_WriteData_DMA((SDRAM_WRITE_READ_ADDR + SDRAM_WRITE_READ_ADDR_OFFSET), sdram_aTxBuffer, SDRAM_BUFFER_SIZE) != HAL_OK)
//		Error_Handler();
//	else
//		printf("SDRAM DMA write data requested\n");
//
//	while (!uwDMA_Transfer_Complete){}
//
//	printf("SDRAM DMA write data completed\n");
//
//	uwDMA_Transfer_Complete = 0;
//
//	if (DISCO_SDRAM_ReadData_DMA((SDRAM_WRITE_READ_ADDR + SDRAM_WRITE_READ_ADDR_OFFSET), sdram_aRxBuffer, SDRAM_BUFFER_SIZE) != HAL_OK)
//		Error_Handler();
//	else
//		printf("SDRAM DMA read data requested\n");
//
//	/* Wait until DMA transfer is complete */
//	while (!uwDMA_Transfer_Complete){}
//
//	printf("SDRAM DMA read data completed\n");
//
//	/* -5- Compare both buffers */
//	if (Buffercmp32(sdram_aTxBuffer, sdram_aRxBuffer, SDRAM_BUFFER_SIZE) > 0)
//		Error_Handler();
//	else
//		printf("SDRAM DMA buffer compare ok\n");
//
//#else
//	Error("To activate SDRAM-DMA test, uncomment #define ALLOCATE_TEST_DATA");
//#endif
//
//}
//
//
//static void Fill_Buffer(uint8_t *pBuffer, uint32_t uwBufferLength, uint32_t uwOffset){
//
//	uint32_t tmpIndex = 0;
//
//	/* Put in global buffer different values */
//	for (tmpIndex = 0; tmpIndex < uwBufferLength; tmpIndex++ ){
//		pBuffer[tmpIndex] = tmpIndex + uwOffset;
//	}
//}
//
//static void Fill_Buffer32(uint32_t *pBuffer, uint32_t uwBufferLenght, uint32_t uwOffset)
//{
//	uint32_t tmpIndex = 0;
//
//	/* Put in global buffer different values */
//	for (tmpIndex = 0; tmpIndex < uwBufferLenght; tmpIndex++ )
//	{
//		//pBuffer[tmpIndex] = tmpIndex + uwOffset;
//		pBuffer[tmpIndex] = uwOffset;
//	}
//}
//
///**
// * @brief  Compares two buffers.
// */
//static uint8_t Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint32_t BufferLength){
//
//	while (BufferLength--){
//		if (*pBuffer1 != *pBuffer2){
//			return 1;
//		}
//
//		pBuffer1++;
//		pBuffer2++;
//	}
//
//	return 0;
//}
//
//static uint8_t Buffercmp32(uint32_t* pBuffer1, uint32_t* pBuffer2, uint16_t BufferLength)
//{
//	while (BufferLength--)
//	{
//		if (*pBuffer1 != *pBuffer2)
//		{
//			return BufferLength;
//		}
//
//		pBuffer1++;
//		pBuffer2++;
//	}
//
//	return 0;
//}
