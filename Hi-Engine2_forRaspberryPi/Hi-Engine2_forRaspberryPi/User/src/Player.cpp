#include "../include/Player.h"


#include "../../Engine/include/IORaspberryPi.h"
#include "../../Engine/include/Unit.h"

#include<math.h>


#include "../../Engine/include/BasicScene.h"
#include "../../Engine/include/SceneManager.h"
#include "../../Engine/include/WorldOutliner.h"
#include "../include/Bullet.h"
#include "../include/TestScene.h"

Player::Player(const FPosition& p, const std::string& name, const std::string& shape, const Area& Area, const std::string& Type): Object(p, name, shape, Area, Type)
{
	input_ = new Input();
	
	is_input_ = false;

	prev_position_ = p;

	
	input_->BindAction("Attack", EInputEvent::IE_Pressed, this, [=]() {
		this->attack();
	});

	input_->BindAction("Up", EInputEvent::IE_Pressed, this, [=]() {
		this->up();
	});
	input_->BindAction("Down", EInputEvent::IE_Pressed, this, [=]() {
		this->down();
	});
	input_->BindAction("Left", EInputEvent::IE_Pressed, this, [=]() {
		this->left();
	});
	input_->BindAction("Right", EInputEvent::IE_Pressed, this, [=]() {
		this->right();
	});

	attack_cnt_ = 0;

	hp_bar_ = new HpBar({ 1,0 }, "HpBar", "HpBar", { 10,1 }, "Widget");
	WorldOutliner::AddObject(hp_bar_);

	hp_ = 0;
}

void Player::Work()
{  
	(*input_)();
	int data = IORaspberryPi::get_joy();
	int pressed_key;

	if(hp_> 30)
	{
		SceneManager::nextScene = new TestScene();
	}

}

void Player::OnCollision(Object* other)
{
	position = prev_position_;
}

void Player::up_hp(int increase)
{
	hp_ += increase;
	hp_bar_->SetArea({ hp_,1 });
}

void Player::control(PLAYER_INPUT player_input_)
{
	prev_position_ = position;

	const auto speed = 0.15f;

	if (player_input_ == UP)
	{
		Translate({ 0,-1 * speed });
	}
	else if (player_input_ == DOWN)
	{
		Translate({ 0,speed });
	}
	else if (player_input_ == LEFT)
	{
		Translate({ -1 * speed,0 });
	}
	else if (player_input_ == RIGHT)
	{
		Translate({ speed  ,0 });
	}
}

void Player::move()
{
	
}

void Player::jump(int i)
{
	return;
}

void Player::attack()
{
	attack_cnt_++;

	FPosition pos = GetPosition() + FPosition(1, 0);
	WorldOutliner::AddObject(new Bullet(pos, "Bullet", "Bullet", { 1,1 }, "", "bullet", {1,0}, 0.1f, this));
	
	
	hp_--;
	if (hp_ < 0)
	{
		hp_ = 0;
	}
	hp_bar_->SetArea({ hp_,1 });
}

void Player::up()
{
	control(UP);
}

void Player::down()
{
	control(DOWN);
}

void Player::left()
{
	control(LEFT);
}

void Player::right()
{
	control(RIGHT);
}
