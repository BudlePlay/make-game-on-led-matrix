#pragma once
#include "../../Engine/include/Object.h"

class Bullet : public Object
{
public:
	Bullet(const FPosition& p, const std::string& name, const std::string& shape, const COLOR color, const Area& Area,
	       const std::string& direction, const std::string& Type, const FPosition forward, const float speed, Object* instigator);

	~Bullet() override;
	void Work() override;
	void OnCollision(Object* other) override;

private:
	float speed;
	FPosition forward_;

	Object* instigator_;
};
