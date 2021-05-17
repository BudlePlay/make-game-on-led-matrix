#include "../include/HpBar.h"

HpBar::HpBar(const FPosition& p, const std::string& name, const Area& Area,
             const std::string& Type): Object(p, name, RED, Area, Type)
{
	
}

HpBar::~HpBar()
{
}

void HpBar::Work()
{
}

void HpBar::OnCollision(Object* other)
{
	
}
