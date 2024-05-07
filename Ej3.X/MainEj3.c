#include "Header.h"
#define _XTAL_FREQ 4000000
// Carrusel

void main(void) {
    OSCCON = 0x6A; //4 Mhz
    TRISD = 0x00; //RD como salida (LEDs)
    TRISB = 0xFF; //RB como entrada (Entradas)
    ANSELD = 0x00; //Puerto D como digital
    ANSELB = 0x00; //Puerto B como digital
    PORTD = 0xFF; //RD0 en 1 (LEDs apagado)
    while (1) {
        for (char i = 0x01; i<0x09;i = i * 2){
            PORTD = i;
            if (PORTD != 0x08){
                if (PORTBbits.RB0) { __delay_ms(200); } else { __delay_ms(1000); }
            }
        }
        for (char i = 0x08; i>0x01;i = i / 2){ // Lo mismo, pero en la otra dirección
            PORTD = i;
            if (PORTBbits.RB0) { __delay_ms(200); } else { __delay_ms(1000); }
        }
    }
}