#include "mbed.h"

PwmOut leds[8] = {p5,p6,p7,p8,p9,p10,p11,p12};
AnalogIn potInput(p15);
double vrijednost = 0;

int main() {
    while(1) {
        vrijednost = (1-potInput.read()) * 8;
        for(int i=0; i<8 ; ++i) leds[i]=vrijednost-i;
        wait(0.1);
    }
}