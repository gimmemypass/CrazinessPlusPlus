#include "InputService.h"
#include <SFML/Graphics/RenderTarget.hpp>

InputService::InputService()
= default;

InputService* InputService::Instance()
{
    if(instance == nullptr)
        instance = new InputService();
    return instance;
}

void InputService::Initialise(sf::RenderWindow* window)
{
    this->window = window;
}

sf::Vector2f InputService::GetMouseWorldPosition() const
{
    const auto mousePosition = sf::Mouse::getPosition(*window);
    const auto position = window->mapPixelToCoords(mousePosition);
    return position;
}
