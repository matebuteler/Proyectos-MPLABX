#include "Header.h"
#define _XTAL_FREQ 4000000
#define LED RD0
#define BTN RB0

// Realizar un programa que cambie el estado del LED conectado en RD0,
// cada vez que se presiona el pulsador conectado en RB0 (al estilo flip flop T (toggle))

void main(void) {
    OSCCON = 0x6A; //4 Mhz
    TRISD = 0x00; //RD como salida (LEDs)
    TRISB = 0xFF; //RB como entrada (Entradas)
    ANSELD = 0x00; //Puerto D como digital
    ANSELB = 0x00; //Puerto B como digital
    PORTD = 0x02; //RD0 en 0 (LEDs apagado)
    char anterior = 0;
    
    while (1) {
        anterior = BTN;
        __delay_ms(10);
/*        if (BTN && !anterior) {
            LED = !LED;
        }*/
        if (BTN == 1 && anterior == 0) {
            LED = !LED;
        }
    }
}