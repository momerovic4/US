//Z1
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
DigitalIn btnColor(p8);

InterruptIn btnKruznicaPress(p5);
InterruptIn btnKvadratPress(p6);
InterruptIn btnTrougaoPress(p7);
InterruptIn btnColorPress(p8);

AnalogIn potRadius(p17);
AnalogIn potXOffset(p15);
AnalogIn potYOffset(p16);
AnalogIn potColor(p18);

void crtajKruznicu();
void crtajKvadrat();
void crtajTrougao();
void fillShape();
void setPosition();
void setColor();

int main() {
    btnKruznicaPress.fall(&crtajKruznicu);
    btnKvadratPress.fall(&crtajKvadrat);
    btnTrougaoPress.fall(&crtajTrougao);
    btnColorPress.fall(&fillShape);
    
    height = ST7789H2_GetLcdPixelHeight();
    width = ST7789H2_GetLcdPixelWidth();
    
    BSP_LCD_Init();
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_SetBackColor(LCD_COLOR_GREEN);
    BSP_LCD_SetFont(&Font16);
}

void crtajKruznicu(){
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    leds = 0X1;
    while(1){
        setPosition();
        BSP_LCD_DrawEllipse(posX,posY,size,size/2);
        wait_ms(10);
    }
}

void crtajKvadrat(){
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    leds = 0X2;
    while(1){
        setPosition();
        BSP_LCD_DrawRect(posX,posY,size,size/2);
        wait_ms(10);
    }
}

void crtajTrougao(){
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    leds = 0X4;
    while(1){
        setPosition();
        double visina = (sqrt(15)*size)/4;
        BSP_LCD_DrawLine(posX,posY,posX+size/2,posY);
        BSP_LCD_DrawLine(posX,posY,posX+(size/4),posY-visina);
        BSP_LCD_DrawLine(posX+(size/4),posY-visina,posX+size/2,posY);
        wait_ms(10);
    }
}

void fillShape(){
    if(leds == 0x01){
        while(1){
            setColor();
            setPosition();
            BSP_LCD_FillEllipse(posX,posY,size,size/2);
            wait_ms(10);
        }
    }else if(leds == 0x02){
        while(1){
            setPosition();
            setColor();
            BSP_LCD_FillRect(posX,posY,size,size/2);
            wait_ms(10);
        }
    }else{
         while(1){
            setPosition();
            setColor();
            double visina = (sqrt(15)*size)/4;
            Point vrhovi[3];
            vrhovi[0].X = posX;
            vrhovi[0].Y = posY;
            vrhovi[1].X = posX+size/2;
            vrhovi[1].Y = posY;
            vrhovi[2].X = posX+(size/4);
            vrhovi[2].Y = posY-visina;
            BSP_LCD_FillPolygon(vrhovi,3);
            wait_ms(10);
        }
    }
}

void setColor(){
    if(potColor.read() <= 0.25) BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
    else if(potColor.read() <= 0.5) BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
    else if(potColor.read() <= 0.75) BSP_LCD_SetTextColor(LCD_COLOR_RED);
    else  BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
}

void setPosition(){
    size = potRadius.read()*MAX_SIZE;
    if(size<MIN_SIZE) size= MIN_SIZE;
    posX = potXOffset.read() * width;
    posY = potYOffset.read() * height;
    BSP_LCD_Clear(LCD_COLOR_WHITE);
}