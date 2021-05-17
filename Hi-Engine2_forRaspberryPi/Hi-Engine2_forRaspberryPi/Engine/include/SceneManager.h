#pragma once


#include "Object.h"
#include "Map.h"

#include "Tools.h"
#include "WorldOutliner.h"
#include <vector>
#include "Unit.h"

class SceneManager
{
protected:
public:
	static SceneManager* nextScene;
	Map* mapPointer;

	int X_SIZE = 0;
	int Y_SIZE = 0;
	SceneManager();

	virtual void Create();; //CallZed when the Application is first created.
	virtual void Render(float dt);;
	virtual void Resize(int x, int y);;
	virtual void Input(float dt);;
	virtual void Pause();; //Stop Game
	virtual ~SceneManager();; //Called when this Game should release all resources.


	void UploadMap(std::vector<Object*> obs);


	void SceneChange(SceneManager* scene);
};
