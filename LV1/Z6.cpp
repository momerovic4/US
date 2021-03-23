#include "mbed.h"

DigitalOut led(LED1);
double T = 1;
double onTime(T);
double offTime(T);
int brojac = 0;

int main(){
    while(1){
        led = 1;
        wait(onTime);
        led = 0;
        wait(offTime);

        brojac++;

        if(brojac < 15 || (brojac>45 && brojac<=60)){
            onTime += 0.06*T;
            offTime -= 0.06*T;
        }else if(brojac > 15 && brojac <= 45) {
            onTime -= 0.06*T;
            offTime += 0.06*T;
        }else if(brojac > 60){
            brojac = 0;
        }
    }
}