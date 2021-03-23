#include "mbed.h"
#include "stm32f413h_discovery_lcd.h"
#include <math.h>

#define MAX_SIZE 100
#define MIN_SIZE 20

int height,width,size,posX,posY;

BusOut leds(LED1,LED2,LED3);

DigitalIn btnKruznica(p5);
DigitalIn btnKvadrat(p6);
DigitalIn btnTrougao(p7);

InterruptIn btnKruznicaPress(p5);
InterruptIn btnKvadratPress(p6);
InterruptIn btnTrougaoPress(p7);

AnalogIn potRadius(p17);
AnalogIn potXOffset(p15);
AnalogIn potYOffset(p16);

void crtajKruznicu();
void crtajKvadrat();
void crtajTrougao();
void setPosition();

int main() {
    btnKruznicaPress.fall(&crtajKruznicu);
    btnKvadratPress.fall(&crtajKvadrat);
    btnTrougaoPress.fall(&crtajTrougao);
    
    height = ST7789H2_GetLcdPixelHeight();
    width = ST7789H2_GetLcdPixelWidth();
    
    BSP_LCD_Init();
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_SetFont(&Font16);
}
void crtajKruznicu(){
    leds = 0X1;
    while(1){
        setPosition();
        BSP_LCD_DrawCircle(posX,posY,size);
        wait_ms(10);
    }
}
void crtajKvadrat(){
    leds = 0X2;
    while(1){
        setPosition();
        BSP_LCD_DrawRect(posX,posY,size,size);
        wait_ms(10);
    }
}
void crtajTrougao(){
    leds = 0X4;
    while(1){
        setPosition();
        double visina = (sqrt(3)*size)/2;
        BSP_LCD_DrawLine(posX,posY,posX+size,posY);
        BSP_LCD_DrawLine(posX,posY,posX+(size/2),posY-visina);
        BSP_LCD_DrawLine(posX+(size/2),posY-visina,posX+size,posY);
        wait_ms(10);
    }
}
void setPosition(){
    size = potRadius.read()*MAX_SIZE;
    if(size<MIN_SIZE) size= MIN_SIZE;
    posX = potXOffset.read() * width;
    posY = potYOffset.read() * height;
    BSP_LCD_Clear(LCD_COLOR_WHITE);
}