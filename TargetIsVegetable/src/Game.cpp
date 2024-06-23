#include "Game.h"
#include <iostream>
#include "Components.h"
#include <SFML/Graphics.hpp>

Game::Game() : registry(),
               statesManager(registry),
               window(sf::VideoMode(512, 512), "TargetIsVegetable"),
			   profiler()
{
}
void Game::Initialize()
{
}

void Game::Run()
{
    std::chrono::steady_clock delta_clock = {};
    ImGui::SFML::Init(window);
    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Time dt = deltaClock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                Finish();
        }
        ImGui::SFML::Update(window, dt);
        profiler.Update(dt.asSeconds());

        window.clear();
        ImGui::SFML::Render(window);
        Update(dt.asSeconds());
        for (auto& ent : registry.view<SpriteRendererComponent>())
        {
            auto& component = registry.get<SpriteRendererComponent>(ent);
			window.draw(component.sprite);
        }
        window.display();
    }

    ImGui::SFML::Shutdown();
}

void Game::Update(float dt)
{
    statesManager.Update(dt);
}

void Game::Finish()
{
    window.close();

}
