#include "mbed.h"
#include "stm32f413h_discovery_lcd.h"

PwmOut led(LED1);
double oldX=10,oldY=230,newX=10,newY=230;
int brojac = 0;

int main() {
    BSP_LCD_Init();
    BSP_LCD_DrawVLine(10,10,220);
    BSP_LCD_DrawHLine(10,230,210);
    
    for(int i=0;i<10;++i) BSP_LCD_DrawHLine(5,i*22+10,10);
     while(1) {
        brojac == 25 ? led=0 : led=led+0.04;
        oldX=newX; oldY=newY;
        newX+=4; newY=230-(led)*220;
        BSP_LCD_DrawLine(oldX,oldY,newX,oldY);
        BSP_LCD_DrawLine(newX,oldY,newX,newY);   
        wait(0.0002);
        if(brojac == 50) break;
        brojac++;
    }
}