#pragma once

#include "../../Engine/include/Object.h"
#include "../../Engine/include/Tools.h"
#include "../../Engine/include/Input.h"

class Player : public Object
{
public:
	Player(const FPosition& p, const std::string& name, const std::string& shape, const Area& Area,
	       const std::string& direction, const std::string& Type);

	void Work() override;
	
	void OnCollision(Object* other) override;

private:
	
	Input* input_;
	
	bool is_input_;
	FPosition prev_position_{0,0};
	void control(PLAYER_INPUT player_input_);
	void move();

	void jump(int i);

	void attack();

	void up();
	void down();
	void left();
	void right();
	int attack_cnt_;
};