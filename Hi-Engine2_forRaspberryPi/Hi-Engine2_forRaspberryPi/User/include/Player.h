#pragma once

#include "../../Engine/include/Object.h"
#include "../../Engine/include/Tools.h"
#include "../../Engine/include/Input.h"
#include "HpBar.h"

class Player : public Object
{
public:
	Player(const FPosition& p, const std::string& name, const Area& Area, const std::string& Type);

	void Work() override;
	
	void OnCollision(Object* other) override;

	void up_hp(int increase);
private:
	
	Input* input_;
	
	bool is_input_;
	FPosition prev_position_{0,0};
	void control(PLAYER_INPUT player_input_);
	void move();

	void jump(int i);

	void attack();
	void print_t1();
	void print_t2();
	void print_t3();
	
	void up();
	void down();
	void left();
	void right();
	int attack_cnt_;

	HpBar* hp_bar_;
	int hp_;
};
