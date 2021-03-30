#include "mbed.h"

PwmOut leds[6] = {p5,p6,p7,p8,p9,p10};
AnalogIn potInput(p15);
double vrijednost = 0;

int main() {
    while(1) {
        vrijednost = (1-potInput.read());
        for(int i=0; i<6 ; ++i) leds[i]=vrijednost;
        wait(0.1);
    }
}