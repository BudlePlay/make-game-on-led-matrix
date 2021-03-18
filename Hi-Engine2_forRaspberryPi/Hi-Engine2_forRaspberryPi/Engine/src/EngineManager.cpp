#include "../include/EngineManager.h"
#include "../../User/include/TestScene.h"

#include <iomanip>
#include <string>



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
			WorldOutliner::AllDestroy();
			this->scene = scene->nextScene;
			scene->Create();
			scene->nextScene = nullptr;

			for (int i = 0; i < 32; i++)
				for (int j = 0; j < 16; j++)
					led_matrix_->set_pixel(i, j, BLACK);

			scene->mapPointer->Print();
		}
	}
}

void EngineManager::BoomCheck()
{
	for (auto my : WorldOutliner::GetObjects())
	{
		for (auto other : WorldOutliner::GetObjects())
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
	for (auto o : WorldOutliner::GetObjects())
	{
		o->Work();
	}
}

void EngineManager::Print_Map()
{
	scene->SceneManager::UploadMap(WorldOutliner::GetObjects());
	
	std::vector<Position> v = scene->mapPointer->ModifiedMap();

	for (Position i : v)
	{
		std::string shape = scene->mapPointer->GetPartOfMap({ i.x, i.y });

		int comparestr = shape.compare("  ");

		COLOR color_ = BLACK;
		if (comparestr == 0)
		{
			color_ = BLACK;
		}
		else
		{
			color_ = TURQUOISE;

			if (shape.compare("aa") == 0)
			{
				color_ = WHITE;
			}
			else if (shape.compare("HpBar") == 0)
			{
				color_ = RED;
			}
			else if (shape.compare("Enemy") == 0)
			{
				color_ = YELLOW;
			}
		}

		if (i.x < 32 && i.y < 16)
		{
			led_matrix_->set_pixel(i.x, i.y, color_);
		}

	}


	led_matrix_->refresh();
}

EngineManager::~EngineManager()
{
	
}
