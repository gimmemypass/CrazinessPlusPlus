#pragma once

#include "imgui.h"
#include <format>

class Profiler
{
private:
	int _fps;
	int _fpsCounter;
	float _fpsTime;
public:
	Profiler();
	void Update(float dt);
};

