#include "MoveBoidsSystem.h"
#include "../Components.h"
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

	auto mousePosition = sf::Mouse::getPosition();
	auto view = reg.view<BoidTagComponent>();
	for (auto& ent : view)
	{
		//todo make movement
	}
}
