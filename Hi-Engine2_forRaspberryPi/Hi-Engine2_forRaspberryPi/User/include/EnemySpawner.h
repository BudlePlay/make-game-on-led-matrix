#pragma once

#include "../../Engine/include/Object.h"
#include "../../Engine/include/Tools.h"

class EnemySpawner : public Object
{
public:
	EnemySpawner(const FPosition& p, const std::string& name, const Area& Area,
		const std::string& Type);

	~EnemySpawner() override;
	void Work() override;
	void OnCollision(Object* other) override;

private:
	int spawntime_ = 100;
	int uptimer_ = 0;
	int enemy_y_ = 1;

	RandomInt random_int_;
};

