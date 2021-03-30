#include "mbed.h"

DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);

int main(){
    while(1){
        myled1 = 1;
        wait(1);
        myled1 = 0;
        wait(1);
        myled2 = 1;
        wait(1);
        myled2 = 0;
        wait(1);
        myled3 = 1;
        wait(1);
        myled3 = 0;
        wait(1);
        myled4 = 1;
        wait(1);
        myled4 = 0;
        wait(1);
    }

    return 0;
}