#include "../include/Input.h"

#include "../../ProjectSetting.h"

#include "../../ProjectSetting.h"
#include "../include/IORaspberryPi.h"

Input::Input()
{
}

void Input::BindAction(std::string name, EInputEvent KeyEvent, Object* object, const std::function<void()>& func)
{
	input_map_.insert(std::make_pair(name, func));
	this->object_ = object;
	this->func_ = func;
}

void Input::operator()() const
{
	int joy = IORaspberryPi::get_joy();

	if (joy != -1)
	{
		const int pressed_key = joy;
		const auto input_setting = InputSetting::Action_map.find(pressed_key);

		if(input_setting != InputSetting::Action_map.end())
		{
			const auto action_name_setting = input_setting->second;
			const auto input = input_map_.find(action_name_setting);

			if (input != input_map_.end())
			{
				input->second();
			}
		}	
	}

	int btn = IORaspberryPi::get_btn(0);
	if (btn != 0)
	{
		const auto input_setting = InputSetting::Action_map.find(10);

		if (input_setting != InputSetting::Action_map.end())
		{
			const auto action_name_setting = input_setting->second;
			const auto input = input_map_.find(action_name_setting);

			if (input != input_map_.end())
			{
				input->second();
			}
		}
	}
	
}
