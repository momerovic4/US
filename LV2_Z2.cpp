#include "mbed.h"
#include "stm32f413h_discovery_lcd.h"
#include <string>

int oldX=15,oldY=225,newX=15,newY=225,t=0;
AnalogIn temp(p15);

int main() {
    BSP_LCD_Init();
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_SetFont(&Font8);
    
    BSP_LCD_DrawVLine(15,35,200);
    BSP_LCD_DrawHLine(10,35,10);
    BSP_LCD_DrawHLine(10,54,10);
    BSP_LCD_DrawHLine(10,73,10);
    BSP_LCD_DrawHLine(10,92,10);
    BSP_LCD_DrawHLine(10,111,10);
    BSP_LCD_DrawHLine(10,130,10);
    BSP_LCD_DrawHLine(10,149,10);
    BSP_LCD_DrawHLine(10,168,10);
    BSP_LCD_DrawHLine(10,187,10);
    BSP_LCD_DrawHLine(10,206,10);
    BSP_LCD_DrawHLine(10,225,200);

    while(1){
        string napon = "Napon: " + std::to_string((int)(temp.read()*1000)) + "mV";
        string temperatura = "Temp: " + std::to_string((int)(temp.read()*100)) + "C";
        string vrijeme = "Vrijeme: " + std::to_string(t) + "s";
        
        BSP_LCD_FillRect(130,0,200,40);
        BSP_LCD_DisplayStringAt(140, 5, (uint8_t*)reinterpret_cast<const uint8_t*>(napon.c_str()), LEFT_MODE);
        BSP_LCD_DisplayStringAt(140, 15, (uint8_t*)reinterpret_cast<const uint8_t*>(temperatura.c_str()), LEFT_MODE);
        BSP_LCD_DisplayStringAt(140, 25, (uint8_t*)reinterpret_cast<const uint8_t*>(vrijeme.c_str()), LEFT_MODE);
        
        BSP_LCD_DrawLine(oldX,oldY,newX,newY);
        BSP_LCD_FillCircle(newX,newY,3);
        BSP_LCD_FillCircle(oldX,oldY,3);
        oldX=newX; oldY=newY;
        newY=225-19*(temp.read()*10); newX+=15;
        t++;
        wait_ms(1000); //Cekamo sekundu
    }
}