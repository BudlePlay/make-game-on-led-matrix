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

#include <random>
#include <time.h>

class RandomInt {
private:
    std::random_device rd;
    int max_roll;
    typedef std::mt19937 MyRng;
    MyRng rng;
    std::uniform_int_distribution<int> dice;
public:
    RandomInt(int MR) : max_roll(MR), rng(rd()), dice(std::uniform_int_distribution<>(1, MR)) {
        rng.seed(::time(NULL));
    }

    int roll() {
        return dice(rng);
    }
};
