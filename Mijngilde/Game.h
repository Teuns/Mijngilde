#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Core.h"

#define FPS 60
#define CELL_SIZE 100

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
    // Level grid (2D array)
    // It's from the bottom to up (so the first row is the bottom ground, then it goes all way up)

    // 1: grass
    // 2: dirt
    // 3: stone
    // 4: coat 
    // 5: glass
    // 6: gold
    // 7: wood
    // 8: sand
    // 9: tnt
        
    int level_grid[7][100] = {
        { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
        { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
        { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
        { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
        { 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2 },
        { 0, 1, 1, 1, 2, 2, 2, 2, 10, 0, 0, 1 },
        { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
    };
    float Framerate;
    float fps;
    sf::Clock Clock;
    std::string new_title;
    sf::Sprite bgSprite;
    sf::IntRect bgRect;
    int enemySpeed = 3;
    int player_vely = 0;
    int jumpDistance = 30;
    int scrollSpeed = 10;
    std::string direction;
    bool jump = false, onBlock = true, scrolling = false;
    int activeBlock = 1;
    std::vector<std::string> blocks = { "grass", "dirt", "stone", "coat", "glass", "gold", "wood", "sand", "tnt" };
protected:
    sf::RenderWindow window;
    int ground_level = 0;
};

#endif
