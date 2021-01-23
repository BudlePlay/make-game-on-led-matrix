#pragma once

#include<iostream>

#include "Unit.h"

class Object
{
protected:
	std::string name;
	std::string shape;
	std::string Type;
	FPosition position{0,0};
	Area area{0,0};
	std::string Direction;
	
	float Speed = 0.2;
	FPosition Up = { 0, Speed };
	FPosition Down = { 0, -Speed };
	FPosition Left = { -Speed, 0 };
	FPosition Right = { Speed, 0 };
	
public:
	
	Object(FPosition p, std::string name, std::string shape, Area Area, std::string direction, std::string Type);


	std::string GetName();

	void SetName(std::string name);

	FPosition GetPosition();

	void SetPosition(FPosition p);

	std::string GetShape();

	void SetShape(std::string shape);

	std::string getDirection();

	void setDirection(std::string D);

	std::string getType();

	void setType(std::string t);


	void Translate(FPosition p);

	void Translate(FPosition p, std::string shape);

	void TryWork();

	Area GetArea();
	virtual void Work();
	virtual void OnCollision(Object* other);
};
