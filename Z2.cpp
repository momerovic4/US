#include "mbed.h"

DigitalOut Red(p5);
DigitalOut Green(p6);
DigitalOut Blue(p7);

int main(){
    double timer = 1;
    while(1){
        Red = 1;
        wait(timer);
        Red = 0;
        wait(timer);
        Green = 1;
        wait(timer);
        Green = 0;
        wait(timer);
        Blue = 1;
        wait(timer);
        Blue = 0;
        wait(timer);
        if(timer != 0.1) timer = timer - 0.1;
    }

    return 0;
}