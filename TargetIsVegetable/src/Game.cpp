#include "Game.h"
#include <iostream>

Game::Game() : _registry(),
               _statesManager(_registry),
               _window(sf::VideoMode(512, 512), "TargetIsVegetable"),
			   _profiler()
{

}
void Game::Initialize()
{
	
}

void Game::Run()
{
    std::chrono::steady_clock delta_clock = {};
    ImGui::SFML::Init(_window);
    sf::Clock deltaClock;
    while (_window.isOpen())
    {
        sf::Time dt = deltaClock.restart();

        Update(dt.asSeconds());

        sf::Event event;
        while (_window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                Finish();
        }
        ImGui::SFML::Update(_window, dt);
        _profiler.Update(dt.asSeconds());

        _window.clear();
        ImGui::SFML::Render(_window);
        _window.display();
    }

    ImGui::SFML::Shutdown();
}

void Game::Update(float dt)
{
    _statesManager.Update(dt);
}

void Game::Finish()
{
    _window.close();

}
