#pragma once
#include <functional>
#include <map>


#include "IORaspberryPi.h"
#include "Object.h"

enum EInputEvent
{
	IE_Pressed = 0,
	IE_Released = 1,
	IE_Repeat = 2,
	IE_DoubleClick = 3,
	IE_Axis = 4,
	IE_MAX = 5,
};

class Input
{
public:
	Input();

	void BindAction(std::string name, EInputEvent KeyEvent, Object* object, const std::function<void()>& func);
	void operator()();

	std::map<std::string, std::function<void()>> input_map_;
private:

	bool flips[BTN_CNT];
	Object* object_;
	std::function<void()> func_;
	
};

