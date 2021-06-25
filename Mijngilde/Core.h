#ifndef CORE_H
#define CORE_H

#include "Entity.h"

class Core
{
public:
    Core();
    sf::Sprite getSprite(std::string sprite);
private:
    std::vector<sf::Sprite> vector_sprites = {};
protected:
    enum Keystates
    {
        up,
        left,
        right,
        down,
        max_keys
    };
    int keystates[max_keys]{};
    std::vector<entity> vector_items = {};
    sf::Texture bgTexture;
};

#endif
