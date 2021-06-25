#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "Main.h"

int main(int argc, char* args[])
{
    Main main;
    std::cout << "Initializing main" << std::endl;
    main.init();

    return 0;
}

int Main::init()
{
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(FPS);
    window.setVerticalSyncEnabled(true);

    std::cout << "Initialized main, running game" << std::endl;

    run();

    return 0;
}