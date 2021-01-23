#include "../include/EngineManager.h"
#include "../../User/include/TestScene.h"

#include <iomanip>
#include <string>

#include "../include/Tools.h"


EngineManager::EngineManager()
{
	led_matrix_ = new IORaspberryPi();
	this->scene = new TestScene();
	
	Game();
}

EngineManager::EngineManager(SceneManager* scene)
{
	led_matrix_ = new IORaspberryPi();
	this->scene = scene;
	Game();
}

void EngineManager::Game()
{
	scene->Create();
	scene->mapPointer->Print();


	while (true)
	{
		scene->mapPointer->CopyCurrentMapANDRemoveCurrentMap();

		//Game
		Work();
		//end

		BoomCheck();

		Print_Map();

		if (scene->nextScene)		//nextScene is not null
		{
			system("cls");
			WorldOutliner::AllDestroy();
			this->scene = scene->nextScene;
			scene->Create();
			scene->nextScene = nullptr;
			scene->mapPointer->Print();
		}
	}
}

void EngineManager::BoomCheck()
{
	for (auto my : scene->worldOutliner.GetObjects())
	{
		for (auto other : scene->worldOutliner.GetObjects())
		{
			if (my != other)
			{
				Position myP = PositionTools::FPtoIP(my->GetPosition());
				Area myA = my->GetArea();
				Position otherP = PositionTools::FPtoIP(
					other->GetPosition());
				Area otherA = other->GetArea();

				if (myP.x + myA.width > otherP.x && myP.x < otherP.x + otherA.width)
				{
					if (myP.y + myA.height > otherP.y && myP.y < otherP.y + otherA.height)
					{
						my->OnCollision(other);
					}
				}
			}
		}
	}
}

void EngineManager::Work()
{
	//Work
	for (auto o : scene->worldOutliner.GetObjects())
	{
		o->Work();
	}
}

void EngineManager::Print_Map()
{
	scene->SceneManager::UploadMap(scene->worldOutliner.GetObjects());

	std::vector<Position> v = scene->mapPointer->ModifiedMap();
	for (Position i : v)
	{
		std::cout << scene->mapPointer->GetPartOfMap({ i.x, i.y }) << std::endl;
	}
	Tools::backCersor();
	
	led_matrix_->refresh();
}

EngineManager::~EngineManager()
{
	
}
