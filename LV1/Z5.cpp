#include "mbed.h"

BusOut LEDS(p9,p10,p11,p12,p13,p14,p15,p16);
DigitalIn  btn1(p5);
DigitalIn  btn2(p6);
DigitalIn  btn3(p7);
DigitalIn  btn4(p8);

InterruptIn btnPress1(p5);
InterruptIn btnPress2(p6);
InterruptIn btnPress3(p7);
InterruptIn btnPress4(p8);

int adding = 1;
char value = 0x00;

void btn1Down();
void btn2Down();
void btn3Down();
void btn4Down();

double timer = 1;

int main(){

    btnPress1.rise(&btn1Down);
    btnPress2.rise(&btn2Down);
    btnPress3.rise(&btn3Down);
    btnPress4.rise(&btn4Down);

    while(1){
        if(adding) value++;
        else value --;
        if(value > 0xFF) value = 0;
        LEDS = value;
        wait(1);
    }
}

void btn1Down()
{
    adding = 1;
}

void btn2Down()
{
    adding = 0;
}

void btn3Down()
{
    timer = timer - 0.1;
}

void btn4Down()
{
    timer = timer + 0.1;
}