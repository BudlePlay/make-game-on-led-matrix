#include "../include/Wall.h"



Wall::Wall(FPosition p, std::string name, std::string shape, Area area, std::string Type): Object(p, name, shape, area, Type)
{
}

void Wall::Work()
{
	Make();
}

void Wall::Make()
{
}

void Wall::OnCollision(Object* other)
{
}

void Wall::Pause()
{
}

Wall::~Wall()
{
}
