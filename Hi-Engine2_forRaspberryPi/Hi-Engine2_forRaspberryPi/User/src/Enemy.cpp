#include "../include/Enemy.h"

#include "../../Engine/include/WorldOutliner.h"
#include "../include/Wall.h"

Enemy::Enemy(const FPosition& p, const std::string& name, const Area& Area,
             const std::string& Type): Object(p, name, YELLOW, Area, Type)
{
}

Enemy::~Enemy()
{
}

void Enemy::Work()
{
	Translate({ -0.01f,0.f });
}

void Enemy::OnCollision(Object* other)
{
	if (dynamic_cast<Wall*>(other))
	{
		WorldOutliner::Destroy(this);
	}
}
