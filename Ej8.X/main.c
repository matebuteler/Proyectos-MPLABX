/*
Realizar un programa que me permita sumar 2 números de 1 digito cada uno. 
Con el botón conectado en RB0 seleccionaré el digito 1, y con el botón conectado en RB1 seleccionaré el segundo digito. 
Al presionar el botón conectado en RB2, se mostrará la suma en los 2 display. 
Si se vuelve a presionar RB2, se vuelve al modo para ingresar los dígitos. Exitoooooooooos!!
 */


#include "Header.h" // include processor files - each processor file is guarded.

#define LED_a RD0
#define LED_b RD1
#define LED_c RD2
#define LED_d RD3
#define LED_e RD4
#define LED_f RD5
#define LED_g RD6
#define com1 RE1
#define com2 RE0
#define BTN1 RB0
#define BTN2 RB1
#define BTNSUM RB2
#define _XTAL_FREQ 4000000

int BTN1_ant = 0, BTN2_ant = 0, BTNSUM_ant = 0, i = 0, j = 0, sum = 0;
bool mode = 0; // 0 es el modo de selección de dígitos, 1 es el modo de suma.
// i es el primer dígito, j es el segundo dígito, sum es la suma.

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
    TRISB = 0b00000111; // RB0, RB1, RB2 como entradas
    OSCCON = 0x6A; //4 Mhz
    TRISD = 0x00; //RD como salida (LEDs)
    TRISE = 0x00; //RE como salida (COMs)
    ANSELD = 0x00; //Puerto D como digital
    ANSELB = 0x00; //Puerto B como digital
    ANSELE = 0x00; //Puerto E como digital
    PORTD = 0xFF; //RD0 en 1 (LEDs apagados)

    // Defines: BTN1 , BTN2 , BTNSUM
    // Variables: BTN1_ant, BTN2_ant, BTNSUM_ant, i, j, sum, mode
    // mode = 0 -> Modo de selección de dígitos
    // mode = 1 -> Modo de suma

    while (1){
        if (BTN1 && !BTN1_ant) { //Sumar 1 a i (Primer dígito)
            i++;
            if (i==10) i = 0;
            __delay_ms(50);
            multiplex(i);
        }
        if (BTN2 && !BTN2_ant) { //Sumar 1 a j (Segundo dígito)
            j++;
            if (j==10) j = 0;
            __delay_ms(50);
            multiplex(j);
        }
        if (BTNSUM && !BTNSUM_ant && !mode) { //Sumar los dígitos
            sum = i + j;
            __delay_ms(50);
            multiplex(sum);
        } 
        BT_ant = BTN;
    }
}