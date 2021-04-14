#include "mbed.h"

BusOut prikaz1(p8, p7, p6, p5);
BusOut prikaz2(p12, p11, p10, p9);

InterruptIn taster(BUTTON1);

const float T(0.2);

int brojac1(0);
int brojac2(0);

bool racunajDrugi = false;

void startStop(){
    racunajDrugi = !racunajDrugi;
}

int main(){
    prikaz1 = brojac1;
    prikaz2 = brojac2;
    taster.fall(&startStop);
    taster.rise(&startStop);
    
    while(1){
        wait(T);
        brojac1 = (brojac1 + 1) % 16;
        if (racunajDrugi) brojac2 = (brojac2 + 1) % 16;
        prikaz1 = brojac1;
        prikaz2 = brojac2;
    }
}