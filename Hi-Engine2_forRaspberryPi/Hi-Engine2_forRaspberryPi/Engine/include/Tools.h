#pragma once


#include "Unit.h"


enum PLAYER_INPUT
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT
};
//change Static 
class Tools
{	
public:
	static void cersorMoveTo(Position p);

	static void backCersor();
};