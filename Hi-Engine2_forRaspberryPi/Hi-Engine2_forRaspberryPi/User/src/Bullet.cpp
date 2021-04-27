#include "../include/Bullet.h"

#include "../../Engine/include/WorldOutliner.h"
#include "../include/Enemy.h"
#include "../include/Player.h"

Bullet::Bullet(const FPosition& p, const std::string& name, const std::string& shape, const COLOR color, const Area& Area, const std::string& direction, const std::string& Type, const FPosition forward, const float speed, Object* instigator): Object(p, name, shape, color, Area, Type)
{
	this->speed = speed;
	this->forward_ = forward;
	this->instigator_ = instigator;
}

Bullet::~Bullet()
{
	std::cout << "dd";
}

void Bullet::Work()
{
	Translate(forward_ * speed);
}

void Bullet::OnCollision(Object* other)
{
	if(dynamic_cast<Enemy*>(other))
	{
		dynamic_cast<Player*>(instigator_)->up_hp(2);
		WorldOutliner::Destroy(other);
	}
	WorldOutliner::Destroy(this);
}
