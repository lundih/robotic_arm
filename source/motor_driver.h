/*
 * motor_driver.h
 *
 *  Created on: Jul 3, 2018
 *      Author: rufusy
 */

#ifndef MOTOR_DRIVER_H_
#define MOTOR_DRIVER_H_


/* declare function prototypes for each task */

void tasks_init();
void drive_motor_1( void *pvParameters );
void drive_motor_2( void *pvParameters );
void drive_motor_3( void *pvParameters );
void drive_motor_4( void *pvParameters );
void drive_motor_5( void *pvParameters );


#endif /* MOTOR_DRIVER_H_ */
