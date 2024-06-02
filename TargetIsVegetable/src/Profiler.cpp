#include "Profiler.h"

Profiler::Profiler() : _fps(0), _fpsTime(0), _fpsCounter(0)
{ 

}
void Profiler::Update(float dt)
{
	_fpsCounter++;
	_fpsTime += dt;
	if (_fpsTime > 1)
	{
		_fps = _fpsCounter;
		_fpsTime = 0;
		_fpsCounter = 0;
	}

	ImGui::Begin("Profiler", (bool*)0, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoResize);
	ImGui::Text(std::format("FPS : {}", _fps).c_str());
	ImGui::End();
}
