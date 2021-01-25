#include <wiringPi.h>

#include "Engine/include/EngineManager.h"
#include "User/include/TestScene.h"

int main(void)
{

	auto engine_manager = new EngineManager(new TestScene());
	
	return 0;
}