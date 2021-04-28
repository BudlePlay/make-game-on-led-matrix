#include "../include/TestScene.h"



#include "../include/EnemySpawner.h"
#include "../include/Player.h"
#include "../include/Wall.h"

TestScene::TestScene(): SceneManager()
{
	X_SIZE = 32;
	Y_SIZE = 16;
	mapPointer = new Map(X_SIZE, Y_SIZE);
}

void TestScene::Create()
{
	Map_Make();

	WorldOutliner::AddObject(new Player({ 1,1 }, "Player", { 1,1 }, "Character"));
	WorldOutliner::AddObject(new EnemySpawner({ 30,5 }, "Spawner", { 1,1 }, "Actor"));

}

void TestScene::Render(float dt)
{
	
}

void TestScene::Resize(int x, int y)
{
}

void TestScene::Input(float dt)
{
}

void TestScene::Pause()
{
}

TestScene::~TestScene()
{
}

void TestScene::Map_Make()
{
	WorldOutliner::AddObject(new Wall(FPosition({0, 0}), "Wall_Top", "бс", Area({X_SIZE, 1}), "Wall"));
	WorldOutliner::AddObject(new Wall(FPosition({ 0, float(Y_SIZE) - 1 }), "Wall_Bottom", "бс", Area({ X_SIZE, 1 }), "Wall"));

	WorldOutliner::AddObject(new Wall(FPosition({0, 0}), "Wall_Left", "бс", Area({1, Y_SIZE}), "Wall"));
	WorldOutliner::AddObject(new Wall(FPosition({float(X_SIZE) - 1, 0}), "Wall_Right", "бс", Area({1, Y_SIZE}), "Wall"));	
}

std::string TestScene::getW()
{
	return WorldOutliner::FindObject("Player")->GetShape();
}
