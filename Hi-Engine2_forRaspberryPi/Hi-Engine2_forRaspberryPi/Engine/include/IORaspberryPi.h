#pragma once
//g++ -o test test.cpp -lwiringPi -lwiringPiDev

#define R1 21
#define R2 16
#define G1 26
#define G2 19
#define B1 20
#define B2 12

#define A 7
#define B 15
#define C 8

#define CLK 25                                                                          
#define LATCH 18
#define OE 24

#define JOY_UP 9
#define JOY_DOWN 10
#define JOY_LEFT 27
#define JOY_RIGHT 22

#define BTN_CNT 4

#define BTN_0 2
#define BTN_1 3
#define BTN_2 4
#define BTN_3 17

#include "../../ProjectSetting.h"


class IORaspberryPi
{
public:
	inline const static int BTN_PIN[BTN_CNT] = { BTN_0, BTN_1, BTN_2, BTN_3 };

	
    unsigned char screen[16][32];

    IORaspberryPi();

    static void clk();

    static void latch();

    static unsigned char bits_from_int(unsigned char mode, unsigned char x);

    void set_row(unsigned char row) const;

    void set_color_top(unsigned char color) const;

    void set_color_bottom(unsigned char color) const;

    void refresh();

    void set_pixel(unsigned char x, unsigned char y, unsigned char color);

    static int get_joy();

    static int get_btn(int num);


};
