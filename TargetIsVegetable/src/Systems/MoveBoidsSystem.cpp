#include "MoveBoidsSystem.h"
#include "../Components.h"
#include "../Utils/SFMLMath.hpp"
#include <SFML/Window.hpp>

MoveBoidsSystem::MoveBoidsSystem(entt::registry& reg) : BaseSystem(reg)
{
}

MoveBoidsSystem::~MoveBoidsSystem() noexcept
{
}

void MoveBoidsSystem::Update(float dt)
{

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
		return;

	sf::Vector2i mousePosition = sf::Mouse::getPosition();
	auto floatMousePosition = sf::Vector2f(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
	auto view = reg.view<BoidTagComponent>();
	for (auto& ent : view)
	{
		auto& transformComponent = reg.get<TransformComponent>(ent);
		auto& movementComponent = reg.get<MovementComponent>(ent);
		auto dir = sf::getNormalized(floatMousePosition - transformComponent.position);
		transformComponent.position = transformComponent.position + dir * movementComponent.speed * dt;
		break;
	}
}
