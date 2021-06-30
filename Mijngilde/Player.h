#ifndef PLAYER_H
#define _PLAYER_H

#include <SFML/Graphics.hpp>
#include <string>

class Player
{
public:
    Player(std::string name);
    std::string getName();
    void setSprite(sf::Sprite sprite);
    void doDamage();
    void move(std::string direction, bool collide = true);
    void setPosition(int x, int y);
    sf::Sprite getPlayer();
    sf::IntRect getPlayerRect();
    std::string getPlayerDirection();
private:
    sf::IntRect player;
    sf::Sprite playerSprite;
    std::string name;
    int speed = 10;
    std::string direction;
protected:
    int playerWidth = 75, playerHeight = 150;
};

#endif
