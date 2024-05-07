/*
 * File:   MainEj1.c
 * Author: Mateo
 *
 * Created on March 12, 2024, 1:03 PM
 */


#include "Header.h"
#define _XTAL_FREQ 4000000
/*
 Realizar un programa que si el pulsador esta presionado, se pueda visualizar un barrido de 4 leds 
 ciclo de ida y vuelta) con retardo de 200mS entre leds 
 (es decir, que cada led se mantiene encendido 200mS). 
 Si el pulsador no esta presionado, el retardo ser� de 1s. Subir el archivo c
Los LED'S estan conectados en los pines RD0, RD1, RD2 y RD3. El boton tiene un resistor de pull up, y esta conectado al pin RB0. 
Subir el archivo .c
 */
void main(void) {
    OSCCON = 0x6A; //4 Mhz
    TRISD = 0x00; //RD como salida (LEDs)
    TRISB = 0xFF; //RB como entrada (Entradas)
    ANSELD = 0x00; //Puerto D como digital
    ANSELB = 0x00; //Puerto B como digital
    PORTD = 0xFF; //RB0 en 1 (LEDs apagado)
    while (1) {
        for (char i, i>0x04,i++){
            PORTD = i;
            __delay_ms(200);
        }
    }
}

