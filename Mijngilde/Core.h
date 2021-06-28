#ifndef CORE_H
#define CORE_H

#include "Entity.h"

class Core
{
public:
    void init();
    sf::Sprite getSprite(std::string sprite);
private:
    std::vector<sf::Sprite> vector_sprites = {};
    std::vector<sf::Texture> vector_textures;
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
    std::vector<enemy> vector_enemies = {};
    sf::Texture bgTexture;
};

#endif
