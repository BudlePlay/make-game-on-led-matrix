#include "../include/EnemySpawner.h"

#include "../../Engine/include/WorldOutliner.h"
#include "../include/Enemy.h"

#include <random>
EnemySpawner::EnemySpawner(const FPosition& p, const std::string& name, const Area& Area,
                           const std::string& Type): Object(p, name, BLACK, Area, Type), random_int_(10)
{
}

EnemySpawner::~EnemySpawner()
{
	
}

void EnemySpawner::Work()
{
	uptimer_++;

	float x = GetPosition().x - 1;
	float y = float(random_int_.roll());
	if(uptimer_ > spawntime_)
	{
		WorldOutliner::AddObject(new Enemy({ x,y}, "Enemy", { 1,1 }, "Character"));
		uptimer_ = 0;
		
		enemy_y_++;
	}
}

void EnemySpawner::OnCollision(Object* other)
{
	
}
