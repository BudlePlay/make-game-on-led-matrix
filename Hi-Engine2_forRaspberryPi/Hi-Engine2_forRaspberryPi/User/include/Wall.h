#pragma once

#include "../../Engine/include/Object.h"

class Wall : public Object {
private:

public:
	
	//WorldOutliner worldOutliner;
	Wall();

	Wall(FPosition p, std::string name, Area area, std::string Type);

	void Work() // 랜더 안에서 돌아가는 Work
	;

	void Make();

	void OnCollision(Object* other);


	void Pause();

	~Wall();
};