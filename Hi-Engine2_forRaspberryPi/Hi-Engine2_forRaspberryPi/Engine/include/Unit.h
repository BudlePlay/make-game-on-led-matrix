#pragma once


struct Position
{
	int x;
	int y;
};


struct FPosition
{
	float x; //1
	float y;//2 
	FPosition() : x(0), y(0) {}
	FPosition(float x_, float y_) : x(x_), y(y_) {}

	FPosition& operator=(const FPosition& a) // a.x \ 3, a.y =4
	{
		x = a.x;
		y = a.y;
		return *this;
	}
	FPosition operator+(const FPosition& a) const
	{
		return FPosition(a.x + x, a.y + y);
	}
	FPosition operator-(const FPosition& a) const
	{
		return FPosition(a.x - x, a.y - y);
	}
	FPosition operator*(const FPosition& a) const
	{
		return FPosition(a.x * x, a.y * y);
	}

	FPosition operator*(const float& a) const
	{
		return FPosition(a * x, a * y);
	}

	bool operator==(const FPosition& a) const
	{
		return (x == a.x && y == a.y);
	}

	

};

struct Area
{
	int width;
	int height;

	Area(int width_, int height_) : width(width_), height(height_){}
};
class PositionTools
{
public:
	static Position FPtoIP(FPosition fp);

	static bool IsEqual(FPosition m, FPosition o);
};