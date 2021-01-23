#pragma once
#include "SceneManager.h"
#include "IORaspberryPi.h"


class EngineManager
{
private:
	char message[1000]{};
	SceneManager* scene;
	IORaspberryPi* led_matrix_;
public:
	EngineManager();

	EngineManager(SceneManager* scene);

	void Game();

	void BoomCheck();

	void Work();

	void Print_Map();

	~EngineManager();
};