#pragma once
#include <SFML/Graphics.hpp>

class InputService
{
    inline static InputService* instance = nullptr;
    InputService();
    sf::RenderWindow* window;

public:
    static InputService* Instance();
    void Initialise(sf::RenderWindow* window);
    sf::Vector2f GetMouseWorldPosition() const; 
};
