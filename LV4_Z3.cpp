#include "mbed.h"
#include "stm32f413h_discovery_ts.h"
#include <iomanip>
#include <sstream>
#include "stm32f413h_discovery_lcd.h"

InterruptIn btnTimer(p5);
InterruptIn btnReset(p6);

std::stringstream stream;
std::string s;

bool broji = 0;
int cleared = 0;
float t=0.00f;

void counting();
void reset();

int main() {
    BSP_LCD_Init();
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    btnTimer.fall(&counting);
    btnReset.fall(&reset);
    while (1) {
        t=t+0.1;
        wait_ms(100);
    }
}

void counting(){
    if(broji){
        broji = false;
        stream.str(std::string());
        stream << std::fixed << std::setprecision(1) << t;
        s = stream.str();
        BSP_LCD_DisplayStringAt(5,cleared*25,(uint8_t*)(s.c_str()), LEFT_MODE);
        cleared++;
    }else{
        broji = true;
        t=0;
    }
}

void reset(){
    cleared = 0;
    BSP_LCD_Clear(LCD_COLOR_WHITE);
}