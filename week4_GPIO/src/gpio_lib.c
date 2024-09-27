/*
 * gpio_lib.c
 *
 *  Created on: 26 sep. 2024
 *      Author: jelme
 */

#include <msp430.h>
#include <stdint.h>
#include <stdbool.h>

uint16_t p[4]={0x0000,0x0001,0x0020,0x0021};
uint16_t b[8]={0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x40};

void pinSet(uint16_t port, uint16_t bit, bool val){
    val ? (*(&P1OUT+p[port]) |= b[bit]) : (*(&P1OUT+p[port]) &= ~b[bit]);
}

void pinToggle(uint16_t port, uint16_t bit){
    *(&P1OUT+p[port]) ^= b[bit];
}

uint16_t pinGet(uint16_t port, uint16_t bit){
    return (*(&P1IN+p[port]) & b[bit]);
}

void pinConfigInput(uint16_t port, uint16_t bit, bool pullResistor, bool pullUP, bool IES, bool IE){
    *(&P1DIR+p[port]) &= ~b[bit];
    pullResistor ? (*(&P1REN+p[port]) |= b[bit]) : (*(&P1REN+p[port]) &= ~b[bit]);
    pullUP ? (*(&P1OUT+p[port]) |= b[bit]) : (*(&P1OUT+p[port]) &= ~b[bit]);
    IES ? (*(&P1IES+p[port]) |= b[bit]) : (*(&P1IES+p[port]) &= ~b[bit]);
    IE ? (*(&P1IE+p[port]) |= b[bit]) : (*(&P1IE+p[port]) &= ~b[bit]);
}

void pinConfigOutput(uint16_t port, uint16_t bit, bool val){
    *(&P1DIR+p[port]) |= b[bit];
    val ? (*(&P1OUT+p[port]) |= b[bit]) : (*(&P1OUT+p[port]) &= ~b[bit]);
}

void pinConfigAnalog(uint16_t port, uint16_t bit){
    *(&P1SEL0+p[port]) |= b[bit];
    *(&P1SEL1+p[port]) |= b[bit];
}
void pinConfigTimer(uint16_t port, uint16_t bit){
    *(&P1DIR+p[port]) |= b[bit];
    *(&P1SEL0+p[port]) |= b[bit];
}
void pinConfigCLK(uint16_t port, uint16_t bit){
    *(&P1DIR+p[port]) |= b[bit];
    *(&P1SEL1+p[port]) |= b[bit];
}
