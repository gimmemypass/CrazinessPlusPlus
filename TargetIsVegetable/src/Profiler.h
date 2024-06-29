#pragma once


class Profiler
{
	int fps;
	int fpsCounter;
	float fpsTime;
public:
	Profiler();
	void Update(float dt);
};

