#pragma once


class Time
{
private:
	unsigned int fps = 0;
	float elapsed_time = 0;
public:
	float deltaTime = 0;

	Time();

	void StartMeasure();

	void EndMeasure();
};