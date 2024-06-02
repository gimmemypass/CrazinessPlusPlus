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
	sf::RenderWindow _window;
	entt::registry _registry;
	StatesManager _statesManager;
	Profiler _profiler;
	void Update(float dt);
public :
	Game();
	void Initialize();
	void Run();
	void Finish();
};

