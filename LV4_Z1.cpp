#include "mbed.h"
#include "C12832.h"

Ticker timer;

C12832 lcd(SPI_MOSI, SPI_SCK, SPI_MISO, p8, p11);

InterruptIn btnStartStop(p8);
InterruptIn btnReset(p9);

int started = 0;
float vrijeme = 0.0f;

void startStop();
void reset();

int main() {
    lcd.cls();
    lcd.locate(0,6);
    lcd.printf("00.0");
    btnStartStop.fall(&startStop);
    btnReset.fall(&reset);
    timer.attach(&reset,99.9);
    while(1){
        if(started){
            lcd.cls();
            lcd.locate(0,6);
            if(vrijeme < 10) lcd.printf("0%.1f",vrijeme);
            else lcd.printf("%.1f",vrijeme);
            vrijeme = vrijeme+0.1;
        }
        wait_ms(100);
    }
}

void startStop(){
    started = !started;
}

void reset(){
    lcd.cls();
    lcd.locate(0,6);
    lcd.printf("00.0");
    vrijeme = 0;
}