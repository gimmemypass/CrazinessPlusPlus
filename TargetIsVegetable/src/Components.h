#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include "Utils/SFMLMath.hpp"

struct SpriteRendererComponent
{
	sf::Sprite sprite;
};

struct TransformComponent
{
	sf::Vector2f position = sf::Vector2f(0,0);
	float rotation = 0;
	sf::Vector2f scale = sf::Vector2f(1,1);
	
	sf::Vector2f GetForward() const
	{
		auto baseForward = sf::Vector2f(0,-1);
		return rotate(baseForward, rotation);		
	}
	sf::Vector2f GetRight() const
	{
		auto baseRight = sf::Vector2f(1,0);
		return rotate(baseRight, rotation);		
	}
	
	void SetForward(const sf::Vector2f to)
	{
		const auto rot = signedAngle(sf::Vector2f(0,-1), to);
		rotation = sf::normalizeAngle(rot);
	}
};

struct BoidTagComponent
{

};

struct MovementComponent
{
	float speed;
};


