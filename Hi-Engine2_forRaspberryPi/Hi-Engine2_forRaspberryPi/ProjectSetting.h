#pragma once

#include <map>
#include <string>


enum COLOR
{
	BLACK = 0,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	PURPLE,
	TURQUOISE,
	WHITE
};


struct InputSetting
{
public:
	static std::map<int,std::string> create_action_map()
	{
		std::map<int, std::string> m;

		m[0] = "Up";
		m[1] = "Down";
		m[2] = "Left";
		m[3] = "Right";
		m[10] = "Attack";
		m[11] = "Hide";
		m[12] = "Menu";
		m[13] = "Test";
		return m;
	}

	const static std::map<int, std::string> Action_map;
};

