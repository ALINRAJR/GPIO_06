

#ifndef GPIO_H_
#define GPIO_H_


/* Private includes ----------------------------------------------------------*/
#include <LPC17xx.h>
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
enum {INPUT=0,OUTPUT};
enum {PIN0=0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7,PIN8,PIN9,PIN10,
	  PIN11,PIN12,PIN13,PIN14,PIN15,PIN16,PIN17,PIN18,PIN19,PIN20,
	  PIN21,PIN22,PIN23,PIN24,PIN25,PIN26,PIN27,PIN28,PIN29,PIN30,PIN31};

#define  PORT0 LPC_GPIO0
#define  PORT1 LPC_GPIO1
#define  PORT2 LPC_GPIO2
#define  PORT3 LPC_GPIO3
#define  PORT4 LPC_GPIO4

/* Private macro -------------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/**
  * @brief Setting direction for GPIO Controller
  * @param[in] usGPIOx specify the Port base address
  * @param[in] ucPinnum specify the Pin number
  * @param[in] ucDirection specify the Direction
  * @return None
  **/
void vGpioSetDir(LPC_GPIO_TypeDef* uiGPIOx, uint8_t ucPinnum,uint8_t ucDirection);


/**
 * @brief Setting Pin as HIGH for GPIO Controller
 * @param[in] usGPIOx specify the Port base address
 * @param[in] ucPinnum specify the Pin number
 * @return None
 **/
void vGpioSetPin(LPC_GPIO_TypeDef* uiGPIOx, uint8_t ucPinnum);

/**
 * @brief Setting Pin as LOW for GPIO Controller
 * @param[in] usGPIOx specify the Port base address
 * @param[in] ucPinnum specify the Pin number
 * @return None
 **/
void vGpioClrPin(LPC_GPIO_TypeDef* uiGPIOx, uint8_t ucPinnum);


/**
 * @brief Setting Nibble starting from the specified Pin number
 * @param[in] uiGPIOx specify the Port base address
 * @param[in] ucPinnum specify the starting Pin number
 * @return None
 **/
void vGpioSetNibble(LPC_GPIO_TypeDef* uiGPIOx, uint8_t ucPinnum, uint8_t ucvalue);

/**
 * @brief Setting Byte starting from the specified Pin number
 * @param[in] uiGPIOx specify the Port base address
 * @param[in] ucPinnum specify the starting Pin number
 * @return None
 **/
void vGpioSetByte(LPC_GPIO_TypeDef* uiGPIOx, uint8_t ucPinnum, uint8_t ucvalue);



#endif /* GPIO_H_ */
