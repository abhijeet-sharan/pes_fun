/*
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    temperature_I2C.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "TMP102.h"
#include <stdint.h>

/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
uint16_t Raw_Temp;
volatile uint8_t Alert_State=0;

int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    PRINTF("Hello World\n");
    I2C_Init();
    I2C_Transmit(CONFIG_REG, CONFIG_BYTE1, CONFIG_BYTE2); // Configure Sensor
    pause();
    //I2C_Transmit(TEMP_LOW_REG, TLOW_1, TLOW_2); // Set Temperature Low Register
    I2C_Transmit(TEMP_HIGH_REG, THIGH_1, THIGH_2);
    pause();
    I2C_Transmit(TEMP_LOW_REG, TLOW_1, TLOW_2);
    pause();
    Raw_Temp=I2C_Read(CONFIG_REG);

    pause();
    Raw_Temp=I2C_Read(TEMP_HIGH_REG);

    pause();
    Raw_Temp=I2C_Read(TEMP_LOW_REG);

    pause();
    Raw_Temp=I2C_Read(TEMP_REG);


//    Alert_State = Alert_Init();
//    PRINTF("\n\rReturned value = %d",Raw_Temp);
//    PRINTF("Alert_State = %d",Alert_State);


    while(1)
    {
    	//pause();
        //Raw_Temp=I2C_Read(TEMP_REG);
       // Alert_State = Alert_Init();
        //PRINTF("\n\rReturned value = %d",Raw_Temp);
        //PRINTF("\n\rAlert_State = %d",Alert_State);
    }
    return 0 ;
}
