#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Core.h"

#define FPS 60
#define CELL_SIZE 50

class Game : public Core
{
public:
    int collide(sf::IntRect player);
    entity getCollide(sf::IntRect player);
    void run();
    void keyHandler();
    void renderLevel();
    void fpsTicker();
private:
    int scrollingOffset = 0;
    // First level grid (2D array) (1 is a block, 0 is not)
    // For the enimies, please keep the enemy path in mind (300)
    // It's from the bottom to up (so the first row is the bottom ground, then it goes all way up)
    int level_grid[5][55] = {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1 },
    };
    float Framerate;
    float fps;
    sf::Clock Clock;
    std::string new_title;
    sf::Sprite bgSprite;
    sf::IntRect bgRect;
    int player_vely = 0;
    int jumpHeight = 30;
    int scrollSpeed = 5;
    std::string direction;
    bool jump = false, onBlock = true, scrolling = false;
protected:
    sf::RenderWindow window;
    int ground_level = 0;
};

#endif
