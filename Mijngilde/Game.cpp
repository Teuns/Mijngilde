#include <iostream>
#include <sstream>
#include "Main.h"
#include "Player.h"

int Game::collide(sf::IntRect player) { // Check if player collides with any objects
    bool _collide = false;
    for (auto& item : vector_items) {
        if (item.obj.intersects(player)) {
            _collide = true;
        }
    };

    return _collide;
};

entity Game::getCollide(sf::IntRect player) { // Return collided object
    entity collide;
    for (auto& item : vector_items) {
        if (item.obj.intersects(player)) {
            collide = item;
            break;
        }
    };

    return collide;
};

void Game::run() {
    // Initialize game
    ground_level = window.getSize().y - CELL_SIZE * sizeof(level_grid) / sizeof(level_grid[0]); // Ground level
    Player player("Teun");
    player.setSprite(getSprite("player")); // Set player sprite
    std::cout << "player name: " << player.getName() << std::endl;
    player.setPosition(player.getPlayer().getTextureRect().left, ground_level - player.getPlayer().getTextureRect().height); // Set player positions
    bgTexture.setRepeated(true);
    bgSprite.setTexture(bgTexture); // Draw background
    while (window.isOpen())
    {
        if (!vector_items.size()) {
            for (int i = 0; i < sizeof(level_grid) / sizeof(level_grid[0]); i++) { // Level
                for (int j = 0; j < sizeof(level_grid[0]) / sizeof(level_grid[0][0]); j++) {
                    int x_pos = j * CELL_SIZE;
                    int y_pos = window.getSize().y - i * CELL_SIZE;

                    if (level_grid[i][j] == 1) { // This is a block tile
                        std::cout << "Drawing tile (block) at [" << i << ", " << j << "]" << std::endl;
                        sf::IntRect rect = { x_pos, y_pos - CELL_SIZE, CELL_SIZE, CELL_SIZE };
                        entity e;
                        e.type = "block";
                        e.obj = rect;
                        vector_items.push_back(e);
                    }
                }
            }
        }
        this->keyHandler();
        if (keystates[right]) {
            player.move("right");
            if (collide(player.getPlayerRect())) {
                player.move("left"); // If colliding, move back
            }
            
            if (player.getPlayerRect().left > (window.getSize().x - player.getPlayerRect().width * 2) - 200) {
                direction = "R";
                scrollingOffset -= scrollSpeed;
                player.move("left");
                scrolling = true;
            }
        }
        if (keystates[left]) {
            player.move("left");
            if (collide(player.getPlayerRect())) {
                player.move("right"); // If colliding, move back
            }
            
            if (player.getPlayerRect().left < player.getPlayerRect().width + 200) {
                direction = "L";
                scrollingOffset += scrollSpeed;
                player.move("right");
                scrolling = true;
            }
        }
        if (keystates[up]) {
            if (player.getPlayerRect().top == ground_level || player.getPlayerRect().top == ground_level - player.getPlayerRect().height) player_vely = -jumpHeight;
            jump = true;
        }
        if (keystates[down]) {
           // Do nothing
        }
        // Render scenes
        window.clear(sf::Color::White);
        // Parallax background
        if (scrollingOffset > (int)bgTexture.getSize().x)
        {
            scrollingOffset = 0;
        }
        bgRect.left = scrollingOffset;
        bgSprite.setTextureRect(sf::IntRect(bgRect.left, 0, window.getSize().x, window.getSize().y));
        window.draw(bgSprite);
        bgRect.left = scrollingOffset + bgTexture.getSize().x;
        bgSprite.setTextureRect(sf::IntRect(bgRect.left, 0, window.getSize().x, window.getSize().y));
        window.draw(bgSprite); // Draw background
        if (scrolling) {
            // clear tiles
            for (entity& rect : vector_items) {
                // increase positions to new direction
                if (direction == "R") rect.obj.left -= scrollSpeed;
                else if (direction == "L") rect.obj.left += scrollSpeed;
            }
            scrolling = false;
        }
        window.draw(player.getPlayer()); // Draw player
        this->renderLevel();
        // Jumping animation
        sf::IntRect m_player = player.getPlayerRect();
        if (jump) {
            if (collide(m_player)) onBlock = !onBlock;
            player_vely += 1;
            m_player.top += player_vely;
            player.setPosition(m_player.left, m_player.top);
            std::cout << "jumping..." << std::endl;
            entity e_collide = getCollide(m_player);
            sf::IntRect _collide = getCollide(m_player).obj;
            // Detect if the player is colliding with a block
            if (e_collide.type != "" && _collide.top > 2) {
                // If the player is colliding from the bottom to the top with a block, then cancel the jump
                if (m_player.top + jumpHeight >= _collide.top + _collide.height) {
                    std::cout << "Hit from under a block!" << std::endl;
                    player_vely = 0;
                }
                else {
                    ground_level = _collide.top - m_player.height;
                }
            }
            else ground_level = window.getSize().y - m_player.height;
            if (m_player.top > ground_level) {
                player_vely = 0;
                m_player.top = ground_level;
                player.setPosition(m_player.left, m_player.top);
                jump = false;
                keystates[up] = false;
                std::cout << "jumping done" << std::endl;
                sf::IntRect temp_m_player = { m_player.left, ground_level + m_player.height, m_player.width, m_player.height };
                entity _collide;
                _collide = getCollide(m_player);
                // Check here if player jumps on a coin
            }
        }
        else {
            // Check if player is still colliding with a block
            sf::IntRect temp_m_player = { m_player.left, ground_level + m_player.height, m_player.width, m_player.height };
            entity _collide;
            _collide = getCollide(temp_m_player);
            if (!collide(temp_m_player)) {
                player_vely = jumpHeight;
                jump = true;
                onBlock = false;
            }
            // Check here if player jumps on a coin
        }
        window.display(); // Display everything
        // Fps counter
        this->fpsTicker();
    }
}

void Game::keyHandler() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::Resized) {
            vector_items.clear();
            window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Fullscreen | sf::Style::Close);
            window.setFramerateLimit(FPS);
            window.setVerticalSyncEnabled(true);
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Right)
            {
                keystates[right] = true;
            }
            else if (event.key.code == sf::Keyboard::Left) {
                keystates[left] = true;
            }
            else if (event.key.code == sf::Keyboard::Up) {
                keystates[up] = true;
            }
            else if (event.key.code == sf::Keyboard::Down) {
                keystates[down] = true;
            }
            else if (event.key.code == sf::Keyboard::F) {
                vector_items.clear();
                window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), WINDOW_TITLE);
                window.setFramerateLimit(FPS);
                window.setVerticalSyncEnabled(true);
            }
        }
        else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Right)
            {
                keystates[right] = false;
            }
            else if (event.key.code == sf::Keyboard::Left) {
                keystates[left] = false;
            }
            else if (event.key.code == sf::Keyboard::Up) {
                keystates[up] = false;
            }
            else if (event.key.code == sf::Keyboard::Down) {
                keystates[down] = false;
            }
        }
    }
}

void Game::renderLevel()
{
    for (entity& rect : vector_items) {
        sf::Sprite sprite = getSprite("");
        sprite.setPosition(sf::Vector2f(rect.obj.left, rect.obj.top));
        if (rect.type == "block") {
            window.draw(sprite);
        }
    }
}

void Game::fpsTicker() {
    if (Clock.getElapsedTime().asSeconds() >= 1.f)
    {
        fps = Framerate;
        Framerate = 0;
        Clock.restart();
    }
    ++Framerate;
    std::stringstream title;
    title << fps;
    title >> new_title;
    new_title = WINDOW_TITLE " " + new_title + " Fps";
    window.setTitle(new_title.c_str());
}