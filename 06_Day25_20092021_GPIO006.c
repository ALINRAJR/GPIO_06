/*
===============================================================================
 Name        : 06_Day25_20092021_GPIO006.c

 Description : Led Blinking program using Board layer and unrolling the delay loop
 	 	 	   and state machines.


 Layered Architecture used for this project
 ************************************
 Application layer-06_Day25_20092021_GPIO006.c
 ************************************
 Board layer - led.c/.h
 ************************************
 Low level drivers or chip level - gpio.c/.h
 ************************************
 Hardware
 ************************************


/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
/* Private includes ----------------------------------------------------------*/
#include "led.h"
/* Private typedef -----------------------------------------------------------*/

/* States of the system */
typedef enum {LEDOFF=0,LEDON=1}States_t;
/* Inputs to the system */
typedef enum {NONE=0,TIMEOUT=1} Inputs_t;

/* Private define ------------------------------------------------------------*/
#define MAXTIMEOUT 0xFFFFFF
/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  Initialize all the hardware connected
  * @retval none
  */
void vAppHardwareInit(void)
{
	vLedInitialize();
}

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

   uint8_t num=0;
   States_t state = LEDOFF;
   Inputs_t input = NONE;
   uint32_t delaycount=0;
  /* MCU Configuration--------------------------------------------------------*/

  /* Initialize all configured peripherals */
   vAppHardwareInit();

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)  // for(;;)
  {

 	  switch(state)
	  {
	   case LEDOFF:
			switch (input) {
			case NONE:
				/* DO NOTHING*/
				break;
			case TIMEOUT:
				vLedOn(LED_0);
				vLedDisplayNum(num);
				num++;
				state = LEDON;
				input = NONE;
				break;
			default:
				/* DO NOTHING*/
				break;
		   }
		  break;
	   case LEDON:
			switch (input) {
			case NONE:
				/* DO NOTHING*/
				break;
			case TIMEOUT:
				 vLedOff(LED_0);
				 state = LEDOFF;
				 input = NONE;
				break;
			default:
				/* DO NOTHING*/
				break;
		   }
	      break;
	   default:
		  /* DO NOTHING */
		  break;
	  }

 	  delaycount++;
 	  if(delaycount>MAXTIMEOUT)
 	  {
 		  input = TIMEOUT;
 		  delaycount=0;

 	  }

  }
  /* End of Application entry point */
}




