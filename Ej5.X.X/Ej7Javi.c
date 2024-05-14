/*ESTE PROGRAMA HACE UNA CUENTA QUE SE INCREMENTA CON RB0 Y MUESTRA DICHA CUENTA EN 2
DISPLAY DE 7 SEGMENTOS  */

#include <xc.h>
#include "Header.h"

#define CERO 0X3F
#define UNO 0X06
#define DOS 0X5B
#define TRES 0X4F
#define CUATRO 0X66
#define CINCO 0X6D
#define SEIS 0X7D
#define SIETE 0X07
#define OCHO 0X7F
#define NUEVE 0X6F


#define _XTAL_FREQ 4000000
int cont = 0, cuenta = 0, caso = 0, EA = 0;
int unidad = 0, decena = 0;
void multiplexar (int num1); //ESTA FUNCION RECIBE UNA VARIABLE Y MANDA AL PUERTO EL VALOR CORRESPONDIENTE PARA QUE SE MUESTRE EL VALOR DE LA MISMA

void main(void)
{
    OSCCON = 0X6B;
    TRISB = 0X01;
    ANSELB = 0X00;
    TRISD = 0X00;
    ANSELD = 0X00;
    PORTD = 0X00;
    TRISE = 0X00;
    ANSELE = 0X00;
//    OPTION_REG = 0X85;  //PRESCALER 1:64
//    INTCON = 0XB0;      //ACTIVO INT EXT Y TIMER0
   
    while(1)
    {
       
    //    __delay_ms(10);
       
       
        decena = cuenta / 10;
        unidad = cuenta - decena*10;
       
       
        EA = RB0;
        multiplexar(decena);    //la función recibe el dato y escribe el valor correspondiente en el puerto D
        RE0 = 1;                //Enciendo display corresponiente (unidad)
        __delay_ms(5);         //tiempo necesario para el ojo humano
        RE0 = 0;
        multiplexar(unidad);    //la función recibe el dato y escribe el valor correspondiente en el puerto D
        RE1 = 1;                //Enciendo display correspondiente (decena)
        __delay_ms(5);         //tiempo necesario para el ojo humano
        RE1 = 0;
        if((EA == 1) && (RB0 == 0)) // HAY FLANCO
        {
            if(cuenta < 99)         //Si la cuenta es menor a 99 (2 display) incremento la misma. Caso contrario, vuelvo a cero
            {
                cuenta++;
            }
            else
            {
                cuenta = 0;
            }
        }
    }
}

void multiplexar (int num)  
{
    switch(num)
    {
        case 0:
            PORTD = CERO;
            break;
        case 1:
            PORTD = UNO;
            break;
        case 2:
            PORTD = DOS;
            break;
        case 3:
            PORTD = TRES;
            break;
        case 4:
            PORTD = CUATRO;
            break;
        case 5:
            PORTD = CINCO;
            break;
        case 6:
            PORTD = SEIS;
            break;
        case 7:
            PORTD = SIETE;
            break;
        case 8:
            PORTD = OCHO;
            break;
        case 9:
            PORTD = NUEVE;
            break;
    }
}