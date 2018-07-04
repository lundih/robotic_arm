/*
 * motor_driver.c
 *
 *  Created on: Jul 3, 2018
 *      Author: rufusy
 *
 *
 *
 * The step and direction signals of the motor driver are connected to the digital pins of the muc.
 * Make the step signal high to enable motor rotation.
 * direction signal is high for clockwise, and low for anti clockwise rotation.
 * configure the motors to run five steps in both directions in an infinite loop
 *
 *
 */

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"

#include "fsl_gpio.h"
#include "fsl_port.h"
#include "FreeRTOS.h"
#include "task.h"
#include "motor_driver.h"

/*
 * Function: tasks_init()
 * description: sets up the tasks to run independently. The function is called in the main method
 * i/p: none
 * return: none
 */

void tasks_init(){

    xTaskCreate(
    		drive_motor_1						// name of function to implement the task
			,  (const portCHAR *)"Motor_1"   	// a name just for humans. not used by FreeRTOS
			,  128  							// Stack size
			,  NULL								// no parameters are passed in the tasks
			,  1  								// priority
			,  NULL								// no need for a task handle
	  );

    xTaskCreate(
    		drive_motor_2
			,	(const portCHAR *)"Motor_2"
			,	128
			,	NULL
			,	1
			,	NULL
    );

    xTaskCreate(
       		drive_motor_3
   			,	(const portCHAR *)"Motor_3"
   			,	128
   			,	NULL
   			,	1
   			,	NULL
    );

    xTaskCreate(
       		drive_motor_4
   			,	(const portCHAR *)"Motor_4"
   			,	128
   			,	NULL
   			,	1
   			,	NULL
    );

    xTaskCreate(
       		drive_motor_5
   			,	(const portCHAR *)"Motor_5"
   			,	128
   			,	NULL
   			,	1
   			,	NULL
    );
}



/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/


void drive_motor_1( void *pvParameters ){
	(void) pvParameters;

	// configure PTA1(D3) and PTB9(D2)

    port_pin_config_t conf;
    conf.mux = 0x01;
    conf.pullSelect = kPORT_PullUp;

    // D3
    PORT_SetPinConfig(PORTA, 1, &conf);
    gpio_pin_config_t pa1confg;
   	pa1confg.pinDirection = kGPIO_DigitalOutput;
   	pa1confg.outputLogic = 1;
   	GPIO_PinInit(GPIOA, 1, &pa1confg);

   	// D2
    PORT_SetPinConfig(PORTB, 9, &conf);
    gpio_pin_config_t pb9config;
	pb9config.pinDirection = kGPIO_DigitalOutput;
   	pb9config.outputLogic = 1;
   	GPIO_PinInit(GPIOB, 9, &pb9config);

   	volatile static int i;

	for(;;){	// A task shall never return or exit

		// pa1config D3 = step signal
		// pb9config D2 = direction signal

		GPIO_PinWrite(GPIOB, 9, 1);

		for(i=0; i<5; i++){
			GPIO_PinWrite(GPIOA, 1, 1);
		    vTaskDelay( 1000 / portTICK_PERIOD_MS );	// wait for one second
			GPIO_PortClear(GPIOA, 1);
		    vTaskDelay( 1000 / portTICK_PERIOD_MS );
		}

	    vTaskDelay( 1000 / portTICK_PERIOD_MS );

		GPIO_PortClear(GPIOB, 9);

		for(i=0; i<5; i++){
			GPIO_PinWrite(GPIOA, 1, 1);
		    vTaskDelay( 1000 / portTICK_PERIOD_MS );
			GPIO_PortClear(GPIOA, 1);
		    vTaskDelay( 1000 / portTICK_PERIOD_MS );
		}

	    vTaskDelay( 1000 / portTICK_PERIOD_MS );

	}
}

void drive_motor_2( void *pvParameters ){
	(void) pvParameters;

	// configure PTA2(D5) and PTB23(D4)

    port_pin_config_t conf;
    conf.mux = 0x01;
    conf.pullSelect = kPORT_PullUp;

    //D5
    PORT_SetPinConfig(PORTA, 2, &conf);
    gpio_pin_config_t pa2confg;
   	pa2confg.pinDirection = kGPIO_DigitalOutput;
   	pa2confg.outputLogic = 1;
   	GPIO_PinInit(GPIOA, 1, &pa2confg);

   	// D4
    PORT_SetPinConfig(PORTB, 23, &conf);
    gpio_pin_config_t pb23config;
	pb23config.pinDirection = kGPIO_DigitalOutput;
   	pb23config.outputLogic = 1;
   	GPIO_PinInit(GPIOB, 9, &pb23config);

   	volatile static int i;

	for(;;){
		 // pa2config D5 = step signal
		 // pb23config D4 = direction signal

		GPIO_PinWrite(GPIOB, 23, 1);

		for(i=0; i<5; i++){
			GPIO_PinWrite(GPIOA, 2, 1);
		    vTaskDelay( 1000 / portTICK_PERIOD_MS );	// wait for one second
			GPIO_PortClear(GPIOA, 2);
		    vTaskDelay( 1000 / portTICK_PERIOD_MS );
		}

	    vTaskDelay( 1000 / portTICK_PERIOD_MS );

		GPIO_PortClear(GPIOB, 23);

		for(i=0; i<5; i++){
			GPIO_PinWrite(GPIOA, 2, 1);
		    vTaskDelay( 1000 / portTICK_PERIOD_MS );
			GPIO_PortClear(GPIOA, 2);
		    vTaskDelay( 1000 / portTICK_PERIOD_MS );
		}

	    vTaskDelay( 1000 / portTICK_PERIOD_MS );


	}
}

void drive_motor_3( void *pvParameters ){
	(void) pvParameters;

	// configure PTC2(D6) and PTC3(D7)

    port_pin_config_t conf;
    conf.mux = 0x01;
    conf.pullSelect = kPORT_PullUp;

    // D6
    PORT_SetPinConfig(PORTC, 2, &conf);
    gpio_pin_config_t pc2config;
   	pc2config.pinDirection = kGPIO_DigitalOutput;
   	pc2config.outputLogic = 1;
   	GPIO_PinInit(GPIOC, 2, &pc2config);

   	//D7
   	PORT_SetPinConfig(PORTC, 3, &conf);
   	gpio_pin_config_t pc3config;
   	pc3config.pinDirection = kGPIO_DigitalOutput;
   	pc3config.outputLogic = 1;
   	GPIO_PinInit(GPIOC, 3, &pc3config);

   	volatile static int i;

	for(;;){
		 // pc2config D6 = step signal
		 // pc3config D7 = direction signal

		GPIO_PinWrite(GPIOC, 3, 1);

		for(i=0; i<5; i++){
			GPIO_PinWrite(GPIOC, 2, 1);
		    vTaskDelay( 1000 / portTICK_PERIOD_MS );	// wait for one second
			GPIO_PortClear(GPIOC, 2);
		    vTaskDelay( 1000 / portTICK_PERIOD_MS );
		}

	    vTaskDelay( 1000 / portTICK_PERIOD_MS );

		GPIO_PortClear(GPIOC, 3);

		for(i=0; i<5; i++){
			GPIO_PinWrite(GPIOC, 2, 1);
		    vTaskDelay( 1000 / portTICK_PERIOD_MS );
			GPIO_PortClear(GPIOC, 2);
		    vTaskDelay( 1000 / portTICK_PERIOD_MS );
		}

	    vTaskDelay( 1000 / portTICK_PERIOD_MS );

	}
}

void drive_motor_4( void *pvParameters ){

	(void) pvParameters;

	// configure PTD0(D10) and PTD2(D11)

	 port_pin_config_t conf;
	 conf.mux = 0x01;
	 conf.pullSelect = kPORT_PullUp;

	 	// D10
	    PORT_SetPinConfig(PORTD, 0, &conf);
	    gpio_pin_config_t pd0config;
	   	pd0config.pinDirection = kGPIO_DigitalOutput;
	   	pd0config.outputLogic = 1;
	   	GPIO_PinInit(GPIOD, 0, &pd0config);

	   	// D11
	    PORT_SetPinConfig(PORTD, 2, &conf);
	    gpio_pin_config_t pd2config;
	   	pd2config.pinDirection = kGPIO_DigitalOutput;
	   	pd2config.outputLogic = 1;
	   	GPIO_PinInit(GPIOD, 2, &pd2config);

	   	volatile static int i;

		for(;;){
			 // pd0config  D10 = step signal
			 // pd2config  D11 = direction signal

			GPIO_PinWrite(GPIOD, 2, 1);

			for(i=0; i<5; i++){
				GPIO_PinWrite(GPIOD, 0, 1);
				vTaskDelay( 1000 / portTICK_PERIOD_MS );	// wait for one second
				GPIO_PortClear(GPIOD, 0);
				vTaskDelay( 1000 / portTICK_PERIOD_MS );
			}

			vTaskDelay( 1000 / portTICK_PERIOD_MS );

			GPIO_PortClear(GPIOD, 2);

			for(i=0; i<5; i++){
				GPIO_PinWrite(GPIOD, 0, 1);
				vTaskDelay( 1000 / portTICK_PERIOD_MS );
				GPIO_PortClear(GPIOD, 0);
				vTaskDelay( 1000 / portTICK_PERIOD_MS );
			}

			vTaskDelay( 1000 / portTICK_PERIOD_MS );


		}
}

void drive_motor_5( void *pvParameters ){
	(void) pvParameters;

	// configure PTD3(D12) and PTD1(D13)

	 port_pin_config_t conf;
	 conf.mux = 0x01;
	 conf.pullSelect = kPORT_PullUp;

	 // D12
	 PORT_SetPinConfig(PORTD, 3, &conf);
	 gpio_pin_config_t pd3config;
	 pd3config.pinDirection = kGPIO_DigitalOutput;
	 pd3config.outputLogic = 1;
	 GPIO_PinInit(GPIOD, 3, &pd3config);

	 // D13
	 PORT_SetPinConfig(PORTD, 1, &conf);
	 gpio_pin_config_t pd1config;
	 pd1config.pinDirection = kGPIO_DigitalOutput;
	 pd1config.outputLogic = 1;
	 GPIO_PinInit(GPIOD, 1, &pd1config);
	 volatile static int i;

		for(;;){
			 // pd3config D12 = step signal
			 // pd1config D13 = direction signal

			GPIO_PinWrite(GPIOD, 1, 1);

			for(i=0; i<5; i++){
				GPIO_PinWrite(GPIOD, 3, 1);
				vTaskDelay( 1000 / portTICK_PERIOD_MS );	// wait for one second
				GPIO_PortClear(GPIOD, 3);
				vTaskDelay( 1000 / portTICK_PERIOD_MS );
			}

			vTaskDelay( 1000 / portTICK_PERIOD_MS );

			GPIO_PortClear(GPIOD, 1);

			for(i=0; i<5; i++){
				GPIO_PinWrite(GPIOD, 3, 1);
				vTaskDelay( 1000 / portTICK_PERIOD_MS );
				GPIO_PortClear(GPIOD, 3);
				vTaskDelay( 1000 / portTICK_PERIOD_MS );
			}

			vTaskDelay( 1000 / portTICK_PERIOD_MS );

		}
}
