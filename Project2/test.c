
/*
 * Team: Abhijeet Dutt Srivastava and Sharan Arumugam
 * PES Project 2
 * C module
 * To compile the code for the FRDM25Z the arm-none-eabi-gcc compiler was used
 * To compile the code for PC cygwin and gcc was used
 */

/**
 *
 * @brief   Application entry point.
 */

/*NOTE ! PCR - PC_Run PCD - PC_Debug FBR - FB_Run FBD - FB_Debug*/

#if defined PCR || defined PCD
 #include<stdio.h>
 #include<stdint.h>
 #include<time.h>
#endif

#if defined FBR || defined FBD
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"

// Delay function
void delay(uint32_t timer)
{
   for(uint32_t i=0;i<timer;i++)
   { __asm("NOP");
    }
}
const uint32_t scaler = 3000;
#endif

#if defined PCR || defined PCD
void LED_RUN(int x)
{
if(x<=5||x==18||x==19)
		printf("LED BLUE ");
if((x>5)&&(x<12))
	printf("LED RED ");;
if((x>11)&&(x<18))
	printf("LED GREEN ");
}

void LED_STATUS(int x)
{
    if(x%2==0)
        printf("ON ");
    else
        printf("OFF ");
}
#endif



#ifdef FBR

/*
 * @brief   Application entry point.
 */
// LED blinking for FB_RUN
void LED_RUN_FBR(int x)
{

if(x<=5||x==18||x==19)
LED_BLUE_TOGGLE();

if((x>5)&&(x<12))
	LED_RED_TOGGLE();
if((x>11)&&(x<18))
	LED_GREEN_TOGGLE();
}
#endif

#ifdef FBD
// LED run function for FB_debug with printfs
void LED_RUN_FBD(int x)
{

if(x<=5||x==18||x==19)
{
	LED_BLUE_TOGGLE();printf("LED BLUE");
}

if((x>5)&&(x<12))
	{
	LED_RED_TOGGLE();printf("LED RED");
	}
if((x>11)&&(x<18))
{
LED_GREEN_TOGGLE();
printf("LED GREEN");
}
}
void LED_STATUS_FBD(int x)
{
    if(x%2==0)
        printf(" ON ");
    else
        printf(" OFF ");
}
#endif

int main(void)
{
// Common for both FB_debug and FB_run
#if defined FBR || defined FBD
/* Board pin, clock, debug console init */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
    /* Delay lookup table */
    uint32_t timing[]={3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600};
LED_BLUE_INIT(1);LED_RED_INIT(1);LED_GREEN_INIT(1);
#endif

while (1)
    {
    	for(int i=0;i<20;i++)
    	{
#if defined PCR || defined PCD
    		time_t Timestamp;
    		uint32_t timing[]={3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600};uint32_t TimeCheck=clock();
#endif

#ifdef FBR
    	LED_RUN_FBR(i);
		delay(timing[i]*scaler);
#endif

#ifdef FBD
		LED_RUN_FBD(i);
		LED_STATUS_FBD(i);
		printf("%d\n",timing[i]*scaler);
		delay(timing[i]*scaler);
#endif
		// GPIO_TogglePinsOutput(BOARD_LED_GPIO, 1u << BOARD_LED_GPIO_PIN);
#if defined PCR || defined PCD
		        LED_RUN(i);
				LED_STATUS(i);
				while((clock()-TimeCheck)<(timing[i]))
		        {
		            __asm("NOP");
		        }
#endif

#ifdef PCD
				printf("%ld \n",clock()-TimeCheck);//for debug
#endif

#ifdef PCD
				TimeCheck=clock();
		        time(&Timestamp);//for debug
		        printf("%s\n",ctime(&Timestamp));//for debug
#endif
        }

}
}
