#include "DEV_Config.h"
#include "EPD_2in13.h"
#include "GUI_Paint.h"
#include "imagedata.h"

unsigned char BlackImage[((EPD_WIDTH % 8 == 0) ? (EPD_WIDTH / 8 ) : (EPD_WIDTH / 8 + 1)) * 50]; //50 line
PAINT_TIME sPaint_time;

void setup()
{
    DEV_ModuleInit();
    if (EPD_Init(FULL_UPDATE) != 0) {
        Serial.print("e-Paper init failed\r\n");
    }
    EPD_Clear();
    DEV_Delay_ms(500);

    EPD_Display((UBYTE *)IMAGE_DATA_2IN13);
    DEV_Delay_ms(500);
    EPD_Clear();

    Paint_NewImage(BlackImage, EPD_WIDTH, 50, 0, WHITE);
    Paint_SelectImage(BlackImage);
    //Paint_SetMirroring(MIRROR_HORIZONTAL); //
    Paint_Clear(0xff);

    Paint_DrawPoint(5, 10, BLACK, DOT_PIXEL_1X1, DOT_STYLE_DFT);
    Paint_DrawPoint(5, 20, BLACK, DOT_PIXEL_2X2, DOT_STYLE_DFT);
    Paint_DrawPoint(5, 30, BLACK, DOT_PIXEL_3X3, DOT_STYLE_DFT);
    Paint_DrawPoint(5, 40, BLACK, DOT_PIXEL_4X4, DOT_STYLE_DFT);

    Paint_DrawLine(20, 10, 60, 50, BLACK, LINE_STYLE_SOLID, DOT_PIXEL_1X1);
    Paint_DrawLine(60, 10, 20, 50, BLACK, LINE_STYLE_SOLID, DOT_PIXEL_1X1);
    Paint_DrawRectangle(20, 10, 60, 50, BLACK, DRAW_FILL_EMPTY, DOT_PIXEL_1X1);
    Paint_DrawRectangle(80, 10, 120, 50, BLACK, DRAW_FILL_FULL, DOT_PIXEL_1X1);
    EPD_DisplayWindows(BlackImage, 0, 0, 122, 50);

    Paint_Clear(0xff);
    Paint_DrawLine(30, 10, 30, 50, BLACK, LINE_STYLE_DOTTED, DOT_PIXEL_1X1);
    Paint_DrawLine(10, 30, 50, 30, BLACK, LINE_STYLE_DOTTED, DOT_PIXEL_1X1);
    Paint_DrawCircle(30, 30, 20, BLACK, DRAW_FILL_EMPTY, DOT_PIXEL_1X1);
    Paint_DrawRectangle(60, 10, 100, 50, BLACK, DRAW_FILL_FULL, DOT_PIXEL_1X1);
    Paint_DrawCircle(80, 30, 20, WHITE, DRAW_FILL_FULL, DOT_PIXEL_1X1);
    EPD_DisplayWindows(BlackImage, 0, 50, 122, 100);

    Paint_Clear(0xff);
    Paint_DrawString_EN(0, 0, "waveshare", &Font12, BLACK, WHITE);
    Paint_DrawNum(0, 20, 1234567, &Font12, BLACK, WHITE);
    EPD_DisplayWindows(BlackImage, 0, 110, 122, 160);
    /*
        Paint_Clear(0xff);
        sPaint_time.Hour = 12;
        sPaint_time.Min = 34;
        sPaint_time.Sec = 56;
        Paint_DrawTime(0, 0, &sPaint_time, &Font20, WHITE, BLACK);

        EPD_DisplayWindows(BlackImage, 0, 170, 122, 220);*/
    EPD_TurnOnDisplay();
    DEV_Delay_ms(500);//Analog clock 1s
    if (EPD_Init(PART_UPDATE) != 0) {
        Serial.print("e-Paper init failed\r\n");
    }
    sPaint_time.Hour = 12;
    sPaint_time.Min = 34;
    sPaint_time.Sec = 56;
}

void loop()
{
    sPaint_time.Sec = sPaint_time.Sec + 1;
    if (sPaint_time.Sec == 60) {
        sPaint_time.Min = sPaint_time.Min + 1;
        sPaint_time.Sec = 0;
        if (sPaint_time.Min == 60) {
            sPaint_time.Hour =  sPaint_time.Hour + 1;
            sPaint_time.Min = 0;
            if (sPaint_time.Hour == 24) {
                sPaint_time.Hour = 0;
                sPaint_time.Min = 0;
                sPaint_time.Sec = 0;
            }
        }
    }
    Paint_Clear(0xff);
    Paint_DrawTime(0, 0, &sPaint_time, &Font20, WHITE, BLACK);

    EPD_DisplayPartWindows(BlackImage, 0, 170, 122, 220);
    EPD_TurnOnDisplay();
    DEV_Delay_ms(500);//Analog clock 1s


}

