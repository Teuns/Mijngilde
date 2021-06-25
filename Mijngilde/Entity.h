#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

typedef struct entity_s {
    sf::IntRect obj;
    std::string type;
} entity;

typedef struct enemy_s {
    sf::IntRect obj;
    std::string type;
    int startX = 0;
    int path = -1;
    int count = 0;
    bool flip = false;
    bool anim = false;
    bool collide = false;
    entity _collide = {};
} enemy;


class Entity
{
public:

private:
	int ground_level = 0;
protected:

};

#endif
