/*
 * File:   main.c
 * Author: Mateo
 *
 * Created on April 23, 2024, 12:02 PM
 */
#include "Header_1.h"
#define LED_a RD0
#define LED_b RD1
#define LED_c RD2
#define LED_d RD3
#define LED_e RD4
#define LED_f RD5
#define LED_g RD6
#define com1 RE1
#define com2 RE0
#define BTN RB0
#define _XTAL_FREQ 4000000

int BT_ant = 0;
int i = 0;
void disp7seg(int n) {
    LED_a = (n != 1 && n != 6 && n != 4);
    LED_b = (n != 5 && n != 6);
    LED_c = (n != 2);
    LED_d = (n != 1 && n != 4 && n != 7 && n != 9);
    LED_e = (n != 1 && n != 3 && n != 4 && n != 5 && n != 7 && n != 9);
    LED_f = (n != 1 && n != 2 && n != 3 && n != 7);
    LED_g = (n != 0 && n != 1 && n != 7);
}

void multiplex(int n) { //com1 = unidad , com2 = decena
    int decena = n/10;
    int unidad = n%10;
    disp7seg(unidad);
    com1 = 1;
    __delay_ms(10);
    com1 = 0;
    disp7seg(decena);
    com2 = 1;
    __delay_ms(10);
    com2 = 0;    
}

void main(void) {
    OSCCON = 0x6A; //4 Mhz
    TRISD = 0x00; //RD como salida (LEDs)
    TRISB = 0xFF; //RB como entrada (Entradas)
    TRISE = 0x00; //RE como salida (COMs)
    ANSELD = 0x00; //Puerto D como digital
    ANSELB = 0x00; //Puerto B como digital
    ANSELE = 0x00; //Puerto E como digital
    PORTD = 0xFF; //RD0 en 1 (LEDs apagado)
    while (1){    
        for (i = 0;(i<100 && BTN == 1 && BT_ant == 0); i++) {
            multiplex(i);
            __delay_ms(100);
            BT_ant = BTN;       
        }    
    }
}