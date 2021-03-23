#include "mbed.h"
#include "C12832.h"

AnalogIn potResistance(p15);
AnalogIn potVoltage(p16);

DigitalIn btnVoltage(p8);
DigitalIn btnResistance(p9);

InterruptIn btnVoltagePress(p8);
InterruptIn btnResistancePress(p9);

void showVoltage();
void showResistance();

C12832 lcd(p5, p7, p6, p11, p12);
 
int main() {
    btnVoltagePress.fall(&showVoltage);
    btnResistancePress.fall(&showResistance);
}

void showVoltage() {
    while(true) {
        lcd.cls();
        lcd.locate(0,3);
        lcd.printf("Calculating Voltage:");
        lcd.locate(0,15);
        lcd.printf("%.2f V",potVoltage.read()*3.3);
        wait_ms(50);
    }
}

void showResistance() {
    while(true) {
        lcd.cls();
        lcd.locate(0,3);
        lcd.printf("Calculating Resistance:");
        lcd.locate(0,15);
        lcd.printf("%.2f kOhm",potResistance.read()*10);
        wait_ms(50);
    }
}