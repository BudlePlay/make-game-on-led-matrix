#pragma once
//g++ -o test test.cpp -lwiringPi -lwiringPiDev


#define R1 17
#define R2 23
#define G1 18
#define G2 24
#define B1 22
#define B2 25

#define A 7
#define B 8
#define C 9

#define CLK 3
#define LATCH 4
#define OE 2

#define JOY_UP 13
#define JOY_DOWN 6
#define JOY_LEFT 19
#define JOY_RIGHT 26

#define BTN_0 16
#define BTN_1 999
#define BTN_2 999
#define BTN_3 999

enum COLOR
{
    BLACK = 0,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    PURPLE,
    TURQUOISE,
    WHITE
};

class IORaspberryPi
{
public:


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
