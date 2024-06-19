#pragma once
#include <SFML/System/Vector2.hpp>

struct TransformComponent
{
	sf::Vector2f position;
	float rotation;
	sf::Vector2f scale;
};

