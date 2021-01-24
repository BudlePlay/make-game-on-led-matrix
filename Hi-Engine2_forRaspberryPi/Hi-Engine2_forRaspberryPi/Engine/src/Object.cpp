#include "../include/Object.h"



Object::~Object()
{
	name.clear();
	shape.clear();
	Type.clear();
}

Object::Object(FPosition p, std::string name, std::string shape, Area Area, std::string Type)
{
	this->name = name;
	this->shape = shape;

	this->position.x = p.x;
	this->position.y = p.y;
	this->area.width = Area.width;
	this->area.height = Area.height;

	this->Type = Type;
}

std::string Object::GetName()
{
	return name;
}

void Object::SetName(std::string name)
{
	this->name = name;
}

FPosition Object::GetPosition()
{
	return position;
}

void Object::SetPosition(FPosition p)
{
	position = p;
}

std::string Object::GetShape()
{
	return shape;
}

void Object::SetShape(std::string shape)
{
	// if shape size is 1 : add " "
	this->shape = shape;
}


std::string Object::getType()
{
	return Type;
}

void Object::setType(std::string t)
{
	this->Type = t;
}


void Object::Translate(FPosition p)
{
	this->position.x += p.x;
	this->position.y += p.y;
}

void Object::Translate(FPosition p, std::string shape)
{
	this->position.x += p.x;
	this->position.y += p.y;
	this->shape = shape;
}

void Object::TryWork()
{
	if (this)
		Work();
}

Area Object::GetArea()
{
	return area;
}

void Object::SetArea(const Area& area)
{
	this->area = area;
}

void Object::Work()
{
}

void Object::OnCollision(Object* other)
{
}
