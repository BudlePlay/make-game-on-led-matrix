#include "../include/Time.h"

Time::Time()
{
}

void Time::StartMeasure()
{
	fps++;
}

void Time::EndMeasure()
{
	elapsed_time += deltaTime;
	//Sleep(10); // if delta time -> 0    time goes slowly
}
