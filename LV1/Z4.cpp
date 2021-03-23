#include "mbed.h"
#include <math.h>

BusOut LEDS(p5,p6,p7,p8,p9,p10,p11,p12);
int stepen = 0;

char value = 0x00;

void btnDown();

int main(){
    while(1){
        value = pow(2,stepen);
        stepen++;
        LEDS = value;
        wait(1);
        if(stepen == 8) stepen = 0;
    }
}