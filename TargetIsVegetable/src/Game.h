#pragma once

#include <entt.hpp>
#include "Common/StatesManager.h"
#include <SFML/Graphics.hpp>
#include <chrono>
#include "imgui-SFML.h"
#include "imgui.h"
#include "Profiler.h"

class Game
{
private :
	sf::RenderWindow window;
	entt::registry registry;
	StatesManager statesManager;
	Profiler profiler;
	void Update(float dt);
public :
	Game();
	void Initialize();
	void Run();
	void Finish();
};

