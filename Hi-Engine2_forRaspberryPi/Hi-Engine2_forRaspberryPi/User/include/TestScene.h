#pragma once

#include "../../Engine/include/SceneManager.h"

class TestScene : public SceneManager
{
private:
public:
	int Count = 100;
	TestScene();
	void Create();

	void Render(float dt);

	void Resize(int x, int y);

	void Input(float dt);

	void Pause();

	~TestScene();

	void Map_Make();

	std::string getW();
};