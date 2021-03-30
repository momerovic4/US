//Zad1

#include "mbed.h"

PwmOut led(p5);
AnalogIn potInput(p15);

int main() {
    while(1) {
        led = potInput.read();
        wait(0.2);
    }
}