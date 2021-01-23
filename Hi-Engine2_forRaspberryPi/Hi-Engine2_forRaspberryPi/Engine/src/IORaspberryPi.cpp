#include "../include/IORaspberryPi.h"




IORaspberryPi::IORaspberryPi()
{


	for (int x = 0; x < 32; x++)
	{
		for (int y = 0; y < 16; y++)
		{
			set_pixel(x, y, BLACK);
		}
	}
	refresh();
}


unsigned char IORaspberryPi::bits_from_int(unsigned char mode, unsigned char x)
{
	if (mode == 0) return x & 1;
	if (mode == 1) return x & 2;
	if (mode == 2) return x & 4;
}


void IORaspberryPi::refresh()
{
	
}

void IORaspberryPi::set_pixel(unsigned char x, unsigned char y, unsigned char color)
{
	screen[y][x] = color;
}

int IORaspberryPi::get_joy()
{
	return -1;
}

int IORaspberryPi::get_btn(int num)
{
	
	return -1;
}

