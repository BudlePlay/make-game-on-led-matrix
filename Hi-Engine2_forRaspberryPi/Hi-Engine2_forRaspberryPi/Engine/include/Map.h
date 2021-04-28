#pragma once

#include<iostream>
#include<vector>

#include "../../ProjectSetting.h"
#include "Unit.h"

class Map
{

private:
	int XSIZE;
	int YSIZE;
public:

	std::vector<std::vector<std::string>>* lastMap;
	std::vector<std::vector<std::string>>* currentMap;


	std::vector<std::vector<COLOR>>* lastColor;
	std::vector<std::vector<COLOR>>* currentColor;
	
	Map();

	Map(int XSIZE, int YSIZE);

	void MapInit();

	void Print();

	void CopyCurrentMapANDRemoveCurrentMap();

	std::vector<Position> ModifiedMap();



	COLOR GetPartOfColor(Position p);
	void SetPartOfColor(Position p, COLOR change, Area area);
	
	int GetYSIZE();
};
