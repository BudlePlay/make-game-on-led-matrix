#pragma once

#include <map>
#include <string>

struct InputSetting
{
public:
	static std::map<int,std::string> create_action_map()
	{
		std::map<int, std::string> m;

		m['w'] = "Up";
		m['s'] = "Down";
		m['a'] = "Left";
		m['d'] = "Right";
		m[' '] = "Attack";
		return m;
	}

	const static std::map<int, std::string> Action_map;
};

