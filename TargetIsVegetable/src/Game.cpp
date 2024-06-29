#include "Game.h"
#include <iostream>
#include "Components.h"
#include <SFML/Graphics.hpp>

Game::Game() : window(sf::VideoMode(1024, 1024), "TargetIsVegetable"),
               statesManager(registry)
{
}
void Game::Initialize()
{
}

void Game::Run()
{
    ImGui::SFML::Init(window);
    sf::Clock deltaClock;
    auto view = sf::View(sf::FloatRect(window.getSize().x / -2.f, window.getSize().y / -2.f, window.getSize().x, window.getSize().y));
	window.setView(view);

    while (window.isOpen())
    {
        sf::Time dt = deltaClock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                Finish();
            if (event.type == sf::Event::Resized)
            {
                view = sf::View(sf::FloatRect(event.size.width/-2.f, event.size.height/-2.f, event.size.width, event.size.height));
                window.setView(view);
            }

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
