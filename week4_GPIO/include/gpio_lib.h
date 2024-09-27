/*
 * gpio_lib.h
 *
 *  Created on: 26 sep. 2024
 *      Author: jelme
 */


#ifndef INCLUDE_GPIO_LIB_H_
#define INCLUDE_GPIO_LIB_H_

#include <msp430.h>
#include <stdint.h>
#include <stdbool.h>

void pinSet(uint16_t port, uint16_t bit, bool val);
void pinToggle(uint16_t port, uint16_t bit);
void pinGet(uint16_t port, uint16_t bit);
uint16_t pinConfigInput(uint16_t port, uint16_t bit, bool pullResistor, bool pullUP, bool IES, bool IE);
void pinConfigOutput(uint16_t port, uint16_t bit, bool val);
void pinConfigAnalog(uint16_t port, uint16_t bit);
void pinConfigTimer(uint16_t port, uint16_t bit);
void pinConfigCLK(uint16_t port, uint16_t bit);



#endif /* INCLUDE_GPIO_LIB_H_ */
