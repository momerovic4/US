//3. Zadatak Prvi dio
#include "mbed.h"

BusOut LEDS(p5,p6,p7,p8,p9,p10,p11,p12);
DigitalIn  btn(BUTTON1);
InterruptIn btnPress(BUTTON1);
int adding = 0;

char value = 0x00;

void btnDown();

int main(){

    btnPress.fall(&btnDown);

    while(1){
        if(!adding) value++;
        else value --;
        if(value > 0xFF) value = 0;
        LEDS = value;
        wait(1);
    }
}

void btnDown()
{
    adding = !adding;
}

//Zadatak 3. (Drugi dio)
//
//#include "mbed.h"
//
//BusOut LEDS(p5,p6,p7,p8,p9,p10,p11,p12);
//DigitalIn  btn(BUTTON1);
//InterruptIn btnPress(BUTTON1);
//int adding = 0;
//
//char value = 0x00;
//
//void btnDown();
//
//int main(){
//
//    btnPress.fall(&btnDown);
//    btnPress.rise(&btnDown);
//
//    while(1){
//        if(!adding) value++;
//        else value --;
//        if(value > 0xFF) value = 0;
//        LEDS = value;
//        wait(1);
//    }
//}
//
//void btnDown()
//{
//    adding = !adding;
//}