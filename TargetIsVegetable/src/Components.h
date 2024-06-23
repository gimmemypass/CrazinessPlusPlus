#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

struct SpriteRendererComponent
{
	sf::Sprite sprite;
};

struct TransformComponent
{
	sf::Vector2f position = sf::Vector2f(0,0);
	float rotation = 0;
	sf::Vector2f scale = sf::Vector2f(1,1);
};


