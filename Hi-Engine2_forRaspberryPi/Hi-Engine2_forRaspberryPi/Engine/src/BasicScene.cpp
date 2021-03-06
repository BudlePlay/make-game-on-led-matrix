#include "../include/BasicScene.h"


#include "../../User/include/TestScene.h"
#include "../../User/include/Wall.h"

BasicScene::BasicScene(): SceneManager()
{
	mapPointer = new Map(30, 30);
}

void BasicScene::Create()
{
	WorldOutliner::AddObject(new Wall(FPosition({0, 0}), "Wall_Top", Area({Size, 1}), "Wall"));
	WorldOutliner::AddObject(new Wall(FPosition({0, 0}), "Wall_Left", Area({1, Size}), "Wall"));
	WorldOutliner::AddObject(new Wall(FPosition({float(Size) - 1, 0}), "Wall_Right", Area({1, Size}), "Wall"));
	WorldOutliner::AddObject(new Wall(FPosition({0, float(Size) - 1}), "Wall_Bottom", Area({Size, 1}), "Wall"));
}

void BasicScene::Render(float dt)
{
	SceneChange(new TestScene);
}

void BasicScene::Resize(int x, int y)
{
}

void BasicScene::Input(float dt)
{
}

void BasicScene::Pause()
{
}

BasicScene::~BasicScene()
{
}
