#include "Profiler.h"
#include "imgui.h"
#include <format>

Profiler::Profiler() : fps(0), fpsCounter(0), fpsTime(0)
{ 

}
void Profiler::Update(float dt)
{
	fpsCounter++;
	fpsTime += dt;
	if (fpsTime > 1)
	{
		fps = fpsCounter;
		fpsTime = 0;
		fpsCounter = 0;
	}

	ImGui::Begin("Profiler", nullptr, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoResize);
	ImGui::Text(std::format("FPS : {}", fps).c_str());
	ImGui::End();
}
