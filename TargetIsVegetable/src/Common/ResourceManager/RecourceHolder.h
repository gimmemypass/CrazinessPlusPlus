#pragma once
#include <SFML/Graphics.hpp>
#include "../../Utils/NonCopyable.h"
#include "../../Utils/NonMoveable.h"
#include "ResourceManager.h"

class ResourceHolder : public NonCopyable, public NonMoveable
{
public:
    static ResourceHolder& Get(){
        static ResourceHolder holder;
        return holder;
    };
    ResourceManager<sf::Texture> textures;
private:
    ResourceHolder()
        : textures("textures", "png"){};
};
