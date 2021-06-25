#include <string>
#include <vector>
#include <iostream>
#include "Game.h"

std::string path = "assets";
std::vector<std::string> sprites = { "", "player" };

Core::Core() {
	for (std::string& sprite : sprites) {
		std::cout << "creating " << sprite << " surface" << std::endl;
		std::string location = path + "/sprites/" + sprite;
		sf::Texture texture;
		texture.create(CELL_SIZE, CELL_SIZE);
		if (sprite != "" && !texture.loadFromFile(location.c_str()))
		{
			std::cout << "Unable to load " << sprite << std::endl;
		}
		sf::Sprite Sprite;
		Sprite.setTexture(texture);
		if (sprite == "") Sprite.setColor({ 32, 191, 107 });
		else if (sprite == "player") Sprite.setColor({ 253, 150, 68 });
		vector_sprites.push_back(Sprite);
	}
	if (!bgTexture.loadFromFile(path + "/sprites/layer_1.png")) {
		std::cout << "Unable to load bgTexture" << std::endl;
	}
}

sf::Sprite Core::getSprite(std::string sprite) {
	auto it = std::find(sprites.begin(), sprites.end(), sprite);

	if (it != sprites.end())
	{
		int index = it - sprites.begin();
		return vector_sprites[index];
	}
}
