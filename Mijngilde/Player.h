#ifndef PLAYER_H
#define _PLAYER_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Game.h"

class Player : public Game
{
public:
    Player(std::string name);
    std::string getName();
    void setSprite(sf::Sprite sprite);
    void doDamage();
    void move(std::string direction);
    void setPosition(int x, int y);
    sf::Sprite getPlayer();
    sf::IntRect getPlayerRect();
private:
    sf::IntRect player;
    sf::Sprite playerSprite;
    std::string name;
    int speed = 5;
protected:

};

#endif
