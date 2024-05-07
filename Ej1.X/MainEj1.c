/*
 * File:   MainEj1.c
 * Author: Mateo
 *
 * Created on March 12, 2024, 1:03 PM
 */


#include "HeaderEj1.h"
#define _XTAL_FREQ 4000000

void main(void) {
    OSCCON = 0x6A; //4 Mhz
    TRISD = 0x7E; //RD0 como salida
    TRISB = 0xFF; //RB como entrada
    ANSELD = 0x00; //Puerto B como digital
    ANSELB = 0x00;
    PORTD = 0x81; //RB0 en 1 (led apagado)
    while (1) {
        while (PORTB) {
            PORTD = 0x81; // Turn on the LED
            __delay_ms(1000); // Delay for 500 milliseconds
            PORTD = 0x80; // Turn off the LED
            __delay_ms(1000); // Delay for 500 milliseconds
    }
    }
}
// Alternative main function to make the LED oscillate
