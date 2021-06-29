#include <iostream>
#include <sstream>
#include "Main.h"

inline bool operator==(const entity& a, const entity& b)
{
    return a.obj.left == b.obj.left && a.obj.top == b.obj.top && a.obj.width == b.obj.width && a.obj.height == b.obj.height;
}

int Game::collide(sf::IntRect player) { // Check if player collides with any objects
    bool _collide = false;
    for (auto& item : vector_items) {
        if (item.obj.intersects(player)) {
            _collide = true;
        }
    };

    for (auto& item : vector_enemies) {
        if (item.obj.intersects(player) && item.obj != player) {
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

    for (auto& item : vector_enemies) {
        if (item.obj.intersects(player) && item.obj != player) {
            collide.obj.left = item.obj.left;
            collide.obj.top = item.obj.top;
            collide.obj.width = item.obj.width;
            collide.obj.height = item.obj.height;
            break;
        }
    };

    return collide;
};

void Game::run() {
    // Initialize game
    init();
    ground_level = window.getSize().y - (CELL_SIZE * sizeof(level_grid) / sizeof(level_grid[0])) - CELL_SIZE; // Ground level
    Player player("Teun");
    player.setSprite(getSprite("player.png")); // Set player sprite
    std::cout << "player name: " << player.getName() << std::endl;
    player.setPosition(player.getPlayer().getTextureRect().left + CELL_SIZE, ground_level - player.getPlayer().getTextureRect().height); // Set player positions
    bgTexture.setRepeated(true);
    bgTexture.setSmooth(true);
    bgSprite.setTexture(bgTexture); // Draw background
    while (window.isOpen())
    {
        if (!vector_items.size()) {
            for (int i = 0; i < sizeof(level_grid) / sizeof(level_grid[0]); i++) { // Level
                for (int j = 0; j < sizeof(level_grid[0]) / sizeof(level_grid[0][0]); j++) {
                    int x_pos = j * CELL_SIZE;
                    int y_pos = window.getSize().y - i * CELL_SIZE;

                    if (level_grid[i][j] == 1) { // This is a grass tile
                        std::cout << "Drawing tile (grass) at [" << i << ", " << j << "]" << std::endl;
                        sf::IntRect rect = { x_pos, y_pos - CELL_SIZE, CELL_SIZE, CELL_SIZE };
                        sf::Sprite sprite = getSprite("grass.png");
                        sprite.setPosition(sf::Vector2f(rect.left, rect.top));
                        entity e;
                        e.type = "grass";
                        e.obj = rect;
                        e.sprite = sprite;
                        vector_items.push_back(e);
                    } 
                    else if (level_grid[i][j] == 2) { // This is a dirt tile
                        std::cout << "Drawing tile (dirt) at [" << i << ", " << j << "]" << std::endl;
                        sf::IntRect rect = { x_pos, y_pos - CELL_SIZE, CELL_SIZE, CELL_SIZE };
                        sf::Sprite sprite = getSprite("dirt.png");
                        sprite.setPosition(sf::Vector2f(rect.left, rect.top));
                        entity e;
                        e.type = "dirt";
                        e.obj = rect;
                        e.sprite = sprite;
                        vector_items.push_back(e);
                    }
                    else if (level_grid[i][j] == 3) { // This is a stone tile
                        std::cout << "Drawing tile (stone) at [" << i << ", " << j << "]" << std::endl;
                        sf::IntRect rect = { x_pos, y_pos - CELL_SIZE, CELL_SIZE, CELL_SIZE };
                        sf::Sprite sprite = getSprite("stone.png");
                        sprite.setPosition(sf::Vector2f(rect.left, rect.top));
                        entity e;
                        e.type = "stone";
                        e.obj = rect;
                        e.sprite = sprite;
                        vector_items.push_back(e);
                    }
                    else if (level_grid[i][j] == 4) { // This is a coat tile
                        std::cout << "Drawing tile (coat) at [" << i << ", " << j << "]" << std::endl;
                        sf::IntRect rect = { x_pos, y_pos - CELL_SIZE, CELL_SIZE, CELL_SIZE };
                        sf::Sprite sprite = getSprite("coat.png");
                        sprite.setPosition(sf::Vector2f(rect.left, rect.top));
                        entity e;
                        e.type = "coat";
                        e.obj = rect;
                        e.sprite = sprite;
                        vector_items.push_back(e);
                    }
                    else if (level_grid[i][j] == 5) { // This is a glass tile
                        std::cout << "Drawing tile (glass) at [" << i << ", " << j << "]" << std::endl;
                        sf::IntRect rect = { x_pos, y_pos - CELL_SIZE, CELL_SIZE, CELL_SIZE };
                        sf::Sprite sprite = getSprite("glass.png");
                        sprite.setPosition(sf::Vector2f(rect.left, rect.top));
                        entity e;
                        e.type = "glass";
                        e.obj = rect;
                        e.sprite = sprite;
                        vector_items.push_back(e);
                    }
                    else if (level_grid[i][j] == 6) { // This is a gold tile
                        std::cout << "Drawing tile (gold) at [" << i << ", " << j << "]" << std::endl;
                        sf::IntRect rect = { x_pos, y_pos - CELL_SIZE, CELL_SIZE, CELL_SIZE };
                        sf::Sprite sprite = getSprite("gold.png");
                        sprite.setPosition(sf::Vector2f(rect.left, rect.top));
                        entity e;
                        e.type = "gold";
                        e.obj = rect;
                        e.sprite = sprite;
                        vector_items.push_back(e);
                    }
                    else if (level_grid[i][j] == 7) { // This is a wood tile
                        std::cout << "Drawing tile (wood) at [" << i << ", " << j << "]" << std::endl;
                        sf::IntRect rect = { x_pos, y_pos - CELL_SIZE, CELL_SIZE, CELL_SIZE };
                        sf::Sprite sprite = getSprite("wood.png");
                        sprite.setPosition(sf::Vector2f(rect.left, rect.top));
                        entity e;
                        e.type = "wood";
                        e.obj = rect;
                        e.sprite = sprite;
                        vector_items.push_back(e);
                    }
                    else if (level_grid[i][j] == 8) { // This is a sand tile
                        std::cout << "Drawing tile (sand) at [" << i << ", " << j << "]" << std::endl;
                        sf::IntRect rect = { x_pos, y_pos - CELL_SIZE, CELL_SIZE, CELL_SIZE };
                        sf::Sprite sprite = getSprite("sand.png");
                        sprite.setPosition(sf::Vector2f(rect.left, rect.top));
                        entity e;
                        e.type = "sand";
                        e.obj = rect;
                        e.sprite = sprite;
                        vector_items.push_back(e);
                    }
                    else if (level_grid[i][j] == 9) { // This is a tnt tile
                        std::cout << "Drawing tile (tnt) at [" << i << ", " << j << "]" << std::endl;
                        sf::IntRect rect = { x_pos, y_pos - CELL_SIZE, CELL_SIZE, CELL_SIZE };
                        sf::Sprite sprite = getSprite("tnt.png");
                        sprite.setPosition(sf::Vector2f(rect.left, rect.top));
                        entity e;
                        e.type = "tnt";
                        e.obj = rect;
                        e.sprite = sprite;
                        vector_items.push_back(e);
                    }
                    else if (level_grid[i][j] == 10) { // This is a cow tile
                        std::cout << "Drawing tile (cow) at [" << i << ", " << j << "]" << std::endl;
                        sf::Sprite sprite = getSprite("cow.png");
                        sf::IntRect rect = { x_pos, y_pos - (int)sprite.getTexture()->getSize().y, CELL_SIZE, CELL_SIZE };
                        sprite.setTextureRect({ 0, 0, (int)sprite.getTexture()->getSize().x, (int)sprite.getTexture()->getSize().y });
                        enemy e;
                        e.type = "cow";
                        e.path = -1;
                        e.startX = rect.left;
                        e.obj = rect;
                        e.sprite = sprite;
                        vector_enemies.push_back(e);
                    }
                    else if (level_grid[i][j] == 11) { // This is a chicken tile
                        std::cout << "Drawing tile (chicken) at [" << i << ", " << j << "]" << std::endl;
                        sf::Sprite sprite = getSprite("chicken.png");
                        sf::IntRect rect = { x_pos, y_pos - (int)sprite.getTexture()->getSize().y, CELL_SIZE, CELL_SIZE };
                        sprite.setTextureRect({ 0, 0, (int)sprite.getTexture()->getSize().x, (int)sprite.getTexture()->getSize().y });
                        enemy e;
                        e.type = "chicken";
                        e.path = 300;
                        e.startX = rect.left;
                        e.obj = rect;
                        e.sprite = sprite;
                        vector_enemies.push_back(e);
                    }
                    else if (level_grid[i][j] == 12) { // This is a pig tile
                        std::cout << "Drawing tile (pig) at [" << i << ", " << j << "]" << std::endl;
                        sf::Sprite sprite = getSprite("pig.png");
                        sf::IntRect rect = { x_pos, y_pos - (int)sprite.getTexture()->getSize().y, CELL_SIZE, CELL_SIZE };
                        sprite.setTextureRect({ 0, 0, (int)sprite.getTexture()->getSize().x, (int)sprite.getTexture()->getSize().y });
                        enemy e;
                        e.type = "pig";
                        e.path = -1;
                        e.startX = rect.left;
                        e.obj = rect;
                        e.sprite = sprite;
                        vector_enemies.push_back(e);
                    }
                }
            }
        }
        this->keyHandler(player);
        entity _collide = getCollide(player.getPlayerRect());
        if (keystates[right]) {
            player.move("right");
            if (collide(player.getPlayerRect())) {
                player.move("left", true); // If colliding, move back
            }
            if (player.getPlayerRect().left > (window.getSize().x - player.getPlayerRect().width * 2) - 200) {
                direction = "R";
                scrollingOffset -= scrollSpeed;
                player.move("left", true);
                scrolling = true;
            }
        }
        if (keystates[left]) {
            player.move("left");
            if (collide(player.getPlayerRect())) {
                player.move("right", true); // If colliding, move back
            }
            if (player.getPlayerRect().left < player.getPlayerRect().width + 200) {
                direction = "L";
                scrollingOffset += scrollSpeed;
                player.move("right", true);
                scrolling = true;
            }
        }
        if (keystates[up]) {
            if (player.getPlayerRect().top == ground_level || player.getPlayerRect().top == ground_level - player.getPlayerRect().height) player_vely = -jumpDistance;
            jump = true;
        }
        // Render scenes
        window.clear(sf::Color::White);
        // Parallax background
        if (scrollingOffset > (int)bgTexture.getSize().x)
        {
            scrollingOffset = 0;
        }
        bgRect.left = scrollingOffset;
        bgSprite.setTextureRect(sf::IntRect(bgRect.left, 0, window.getSize().x, bgTexture.getSize().y));
        window.draw(bgSprite);
        bgRect.left = scrollingOffset + bgTexture.getSize().x;
        bgSprite.setTextureRect(sf::IntRect(bgRect.left, 0, window.getSize().x, bgTexture.getSize().y));
        window.draw(bgSprite); // Draw background
        if (scrolling) {
            // Clear tiles
            for (entity& rect : vector_items) {
                // Increase positions to new direction
                if (direction == "R") rect.obj.left -= scrollSpeed;
                else if (direction == "L") rect.obj.left += scrollSpeed;
            }
            for (enemy& rect : vector_enemies) {
                // Increase positions to new direction
                if (direction == "R") {
                    rect.obj.left -= scrollSpeed;
                    rect.startX -= scrollSpeed;
                }
                else if (direction == "L") {
                    rect.obj.left += scrollSpeed;
                    rect.startX += scrollSpeed;
                }
            }
            scrolling = false;
        }
        window.draw(player.getPlayer()); // Draw player
        this->renderLevel();
        sf::IntRect m_player = player.getPlayerRect();
        // Animate enemies
        for (enemy& enemy : vector_enemies) {
            // Scrolling doesn't work very well
            enemy.obj.left = enemy.count + enemy.startX;
            enemy.sprite.setPosition(sf::Vector2f(enemy.obj.left, enemy.obj.top));
            if (enemy.flip) {
                enemy.sprite.setScale(-1, 1);
                enemy.obj.width = -(int)enemy.sprite.getTexture()->getSize().x;
                enemy.obj.height = enemy.sprite.getTexture()->getSize().y;
            }
            else {
                enemy.sprite.setScale(1, 1);
                enemy.obj.width = enemy.sprite.getTexture()->getSize().x;
                enemy.obj.height = enemy.sprite.getTexture()->getSize().y;
            }
            window.draw(enemy.sprite);
            enemy.collide = collide(enemy.obj);
            enemy._collide = getCollide(enemy.obj);
            if (enemy.obj.intersects(player.getPlayerRect())) {
                player.doDamage();
                if (enemy.anim == false) player.move("right", true);
                else player.move("left", true);
                continue;
            }
            else {
                enemy.count += enemySpeed;
                if (enemy.path > 0 && enemy.count > enemy.path || enemy.path == -1 && enemy.count > enemy._collide.obj.width && enemy.collide) {
                    enemy.count -= enemySpeed;
                    enemy.anim = true;
                }
                if (enemy.anim) {
                    enemy.flip = true;
                    enemy.count -= enemySpeed * 2;
                    if (enemy.path > 0 && enemy.obj.left < enemy.startX || enemy.path == -1 && enemy.count < enemy._collide.obj.width && enemy.collide) {
                        enemy.count += enemySpeed;
                        enemy.anim = false;
                        enemy.flip = false;
                    }
                }
            }
        }
        // Jumping animation
        if (jump) {
            if (collide(m_player)) onBlock = !onBlock;
            player_vely += 1;
            m_player.top += player_vely;
            player.setPosition(m_player.left, m_player.top);
            std::cout << "jumping..." << std::endl;
            entity e_collide = getCollide(m_player);
            sf::IntRect _collide = getCollide(m_player).obj;
            // Detect if the player is colliding with a block
            // Glitches still possible while moving in the air
            if (collide(m_player)) {
                // If the player is colliding from the bottom to the top with a block, then cancel the jump
                if (m_player.top + jumpDistance >= _collide.top + _collide.height) {
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
                sf::IntRect temp_m_player = { m_player.left, ground_level + CELL_SIZE, m_player.width, m_player.height };
                entity _collide;
                _collide = getCollide(m_player);
                // Check here if player jumps on a coin
            }
        }
        else {
            player.setPosition(m_player.left, m_player.top);
            // Check if player is still colliding with a block
            sf::IntRect temp_m_player = { m_player.left, ground_level + 25, m_player.width, m_player.height };
            entity _collide;
            _collide = getCollide(temp_m_player);
            if (!collide(temp_m_player) && m_player.top != window.getSize().y - m_player.height) {
                player_vely = jumpDistance;
                jump = true;
                onBlock = false;
            }
            else if (collide(m_player)) {
                entity _collide;
                _collide = getCollide(m_player);
                m_player.left = _collide.obj.left - _collide.obj.width;
                m_player.top = _collide.obj.top - _collide.obj.height;
                player.setPosition(m_player.left, m_player.top);
            }
            // Check here if player jumps on a coin
        }
        window.display(); // Display everything
        // Fps counter
        this->fpsTicker();
    }
}

void Game::keyHandler(Player player) {
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
        else if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
            sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
            int xIndex = (int)std::floor(worldPos.y / CELL_SIZE);
            int yIndex = (int)std::floor((worldPos.x - scrollingOffset) / CELL_SIZE);
            int x_pos = yIndex * CELL_SIZE;
            int y_pos = xIndex * CELL_SIZE;
            if ((player.getPlayerRect().left < player.getPlayerRect().width
                || player.getPlayerRect().left >(window.getSize().x - player.getPlayerRect().width * 2)) == false) {
                if (event.mouseButton.button == sf::Mouse::Right) {
                    std::cout << "Drawing tile at [" << xIndex << ", " << yIndex << "]" << std::endl;
                    sf::IntRect rect = { x_pos + scrollingOffset, y_pos, CELL_SIZE, CELL_SIZE };
                    sf::Sprite sprite = getSprite(sprites[activeBlock + 1]);
                    sprite.setPosition(sf::Vector2f(rect.left, rect.top));
                    entity e;
                    e.type = blocks[activeBlock];
                    e.obj = rect;
                    e.sprite = sprite;
                    vector_items.push_back(e);
                }
                else if (event.mouseButton.button == sf::Mouse::Left) {
                    std::cout << "Removing tile at [" << xIndex << ", " << yIndex << "]" << std::endl;
                    sf::IntRect rect = { x_pos + scrollingOffset, y_pos, CELL_SIZE, CELL_SIZE };
                    entity e;
                    e.obj = rect;
                    vector_items.erase(
                        std::remove_if(vector_items.begin(), vector_items.end(), [e](entity v) { return v == e; }),
                        vector_items.end());
                }
            }
        }
        else if (event.type == sf::Event::MouseWheelScrolled) {
            if (event.mouseWheelScroll.delta < 0) {
                if (blocks.size() <= activeBlock + 1 == false) activeBlock++;
            }
            else if (event.mouseWheelScroll.delta > 0) {
                if (blocks.size() <= activeBlock - 1 == false) activeBlock--;
            }
        }
    }
}

void Game::renderLevel()
{
    for (entity& rect : vector_items) {
        rect.sprite.setPosition(rect.obj.left, rect.obj.top);
        window.draw(rect.sprite);
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