/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void transmit_data(unsigned char data){
    int i;
    for(i = 0; i<8; ++i){
        // Sets SRCLR to 1 allowing data to be set
        // Also clears SRCLK in preparation of sending data
        PORTB = 0x08;
        // set SER = next bit of data to be sent.
        PORTB |= ((data >> i) & 0x01);
        // set SRCLK = 1 Rising edge shifts next bit of data into the shift register
        PORTB |= 0x02;
    }
    //set RCLK = 1. Rising edge copies data from "Shift" register to "Storage" register
    PORTB |= 0x04;
    //clears all lines in preparation of a new transmission
    PORTB = 0x00;
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRB = 0xFF;
    PORTB = 0x00;
    DDRD = 0xFF;
    PORTD = 0x00;
    /* Insert your solution below */
    while (1) {
        PORTB = 0xFF;
        PORTD = 0x00;
    }
    return 1;
}
