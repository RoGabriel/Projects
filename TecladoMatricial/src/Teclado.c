/*
 * Teclado.c
 *
 *  Created on: 18 de abr. de 2016
 *      Author: Leo
 */

#include "teclado.h"
#include "puertos.h"

#define KEYBOARD_MAX_ROWS       4
#define KEYBOARD_MAX_COLUMNS    3

#define KEYBOARD_SCAN_STATE_START	0
#define KEYBOARD_SCAN_STATE_COL_LOW	1
#define KEYBOARD_SCAN_STATE_READ_ROWS	2

int32_t i=0;
int32_t r=0;
int32_t c=0;

typedef struct
{
    int8_t port;
    int8_t portBit;
    int8_t gpio;
    int8_t gpioBit;
    int8_t func;

}KeyboardPinInfo;

typedef struct {
	int rows;
	int columns;
	int enable;
	int stateMatrix[KEYBOARD_MAX_ROWS][KEYBOARD_MAX_COLUMNS];
	int currentCol;
	int state;
}KeyboardInfo;

static KeyboardPinInfo keyboardRowsPinInfo[]={
        {4,0,2,0,SCU_MODE_FUNC0},{4,1,2,1,SCU_MODE_FUNC0},{4,2,2,2,SCU_MODE_FUNC0},{4,3,2,3,SCU_MODE_FUNC0}
};

static KeyboardPinInfo keyboardColsPinInfo[]={
        {1,5,1,8,SCU_MODE_FUNC0},{7,4,3,12,SCU_MODE_FUNC0},{7,5,3,13,SCU_MODE_FUNC0}//,{6,12,2,8,SCU_MODE_FUNC0}
};

static volatile KeyboardInfo keyboardInfo;


void Board_KEYBOARD_Init(uint8_t rows, uint8_t columns)
{
	keyboardInfo.enable=0;

	if(rows>KEYBOARD_MAX_ROWS)
		rows=KEYBOARD_MAX_ROWS;
	if(columns>KEYBOARD_MAX_COLUMNS)
		columns=KEYBOARD_MAX_COLUMNS;

	keyboardInfo.rows=rows;
	keyboardInfo.columns=columns;

        // configure Rows (Input)

        for(i=0 ; i<rows; i++)
        {
            Chip_SCU_PinMuxSet(keyboardRowsPinInfo[i].port, keyboardRowsPinInfo[i].portBit, (SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | keyboardRowsPinInfo[i].func));
            Chip_GPIO_SetPinDIRInput(LPC_GPIO_PORT, keyboardRowsPinInfo[i].gpio, keyboardRowsPinInfo[i].gpioBit);
        }


	// configure Columns (output)
        for(i=0 ; i<columns; i++)
        {
            Chip_SCU_PinMuxSet(keyboardColsPinInfo[i].port, keyboardColsPinInfo[i].portBit, (SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | keyboardColsPinInfo[i].func));
            Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, keyboardColsPinInfo[i].gpio, keyboardColsPinInfo[i].gpioBit);

	    Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, keyboardColsPinInfo[i].gpio, keyboardColsPinInfo[i].gpioBit);
        }

	keyboardInfo.state=KEYBOARD_SCAN_STATE_START;

	for(r=0; r<KEYBOARD_MAX_ROWS; r++)
	{
	    for(c=0; c<KEYBOARD_MAX_COLUMNS; c++)
		keyboardInfo.stateMatrix[r][c]=1;
	}
	keyboardInfo.enable=1;
}

void Board_KEYBOARD_tick_ms(void)
{
	if(keyboardInfo.enable==1)
	{
		switch(keyboardInfo.state)
		{
			case KEYBOARD_SCAN_STATE_START:
			{
				keyboardInfo.currentCol=0;
				keyboardInfo.state=KEYBOARD_SCAN_STATE_COL_LOW;
				break;
			}
			case KEYBOARD_SCAN_STATE_COL_LOW:
			{
				if(keyboardInfo.currentCol>=keyboardInfo.columns)
				{
					keyboardInfo.state=KEYBOARD_SCAN_STATE_START;
				}
				else
				{
					// set col low
	                Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, keyboardColsPinInfo[keyboardInfo.currentCol].gpio, keyboardColsPinInfo[keyboardInfo.currentCol].gpioBit);
					keyboardInfo.state=KEYBOARD_SCAN_STATE_READ_ROWS;
				}
				break;
			}
			case KEYBOARD_SCAN_STATE_READ_ROWS:
			{
				// read rows
                        	int row;
                        	for(row=0; row<keyboardInfo.rows;row++)
                        	{
                                	int rowVal = Chip_GPIO_GetPinState(LPC_GPIO_PORT, keyboardRowsPinInfo[row].gpio, keyboardRowsPinInfo[row].gpioBit);
                                	keyboardInfo.stateMatrix[row][keyboardInfo.currentCol] = rowVal;
                        	}
                                // set col high
                                Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, keyboardColsPinInfo[keyboardInfo.currentCol].gpio, keyboardColsPinInfo[keyboardInfo.currentCol].gpioBit);
				keyboardInfo.currentCol++;
				keyboardInfo.state=KEYBOARD_SCAN_STATE_COL_LOW;
				break;
			}
		}
	}
}

int Board_KEYBOARD_readMatrix(uint8_t row,uint8_t col)
{
	return keyboardInfo.stateMatrix[row][col];
}

void Board_KEYBOARD_enable(void)
{
	keyboardInfo.enable=1;
}
void Board_KEYBOARD_disable(void)
{
	keyboardInfo.enable=0;
}


