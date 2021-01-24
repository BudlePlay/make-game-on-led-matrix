#pragma once
#include "../../Engine/include/Object.h"

class Enemy : public Object
{
public:
	Enemy(const FPosition& p, const std::string& name, const std::string& shape, const Area& Area,
	      const std::string& Type);

	~Enemy() override;
	void Work() override;
	void OnCollision(Object* other) override;
};

