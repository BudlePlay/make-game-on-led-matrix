#include "../include/Map.h"

Map::Map()
{
	this->XSIZE = 20;
	this->YSIZE = 20;
	MapInit();
}

Map::Map(int XSIZE, int YSIZE)
{
	this->XSIZE = XSIZE;
	this->YSIZE = YSIZE;
	MapInit();
}

void Map::MapInit()
{
	lastColor = new std::vector<std::vector<COLOR>>(YSIZE, std::vector<COLOR>(XSIZE, BLACK));
	currentColor = new std::vector<std::vector<COLOR>>(YSIZE, std::vector<COLOR>(XSIZE, BLACK));
}

void Map::Print()
{
	std::cout << "print" << std::endl;
}

void Map::CopyCurrentMapANDRemoveCurrentMap()
{

	*lastColor = *currentColor;

	for (auto& col : *currentColor)
		for (auto& cor: col)
			cor = BLACK;
}

std::vector<Position> Map::ModifiedMap()
{
	std::vector<Position> positions;
	for (int y = 0; y < YSIZE; y++) //¹Ù²Ù±â
	{
		for (int x = 0; x < XSIZE; x++)
		{
			
			if (currentColor->at(y).at(x) != lastColor->at(y).at(x))
				positions.push_back({ x, y });

		}
	}

	
	return positions;
}


COLOR Map::GetPartOfColor(Position p)
{
	return currentColor->at(p.y).at(p.x);
}

void Map::SetPartOfColor(Position p, COLOR change, Area area)
{
	for (int y = p.y; y < area.height + p.y; y++)
	{
		for (int x = p.x; x < area.width + p.x; x++)
		{
			currentColor->at(y).at(x) = change;
		}
	}
}


int Map::GetYSIZE()
{
	return YSIZE;
}
