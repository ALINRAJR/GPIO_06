
#ifndef CONFIGBOARD_H_
#define CONFIGBOARD_H_


/* Private includes ----------------------------------------------------------*/
#include <LPC17xx.h>


/* Board defines ------------------------------------------------------------*/
#define configLED     1

#if configLED
#define LED0PORT  PORT1
#define LED1PORT  PORT1
#define LED2PORT  PORT1

/* TODO : Update the #defines for PORT for 6 more LEDs */

#define LED0PIN   PIN29
#define LED1PIN   PIN19
#define LED2PIN   PIN20

/* TODO : Update the #defines for PINs for 6more LEDs */

#endif





#endif /* CONFIGBOARD_H_ */
