#include <string>
#include <vector>
#include <iostream>
#include "Game.h"

std::string path = "assets";

void Core::init() {
	for (std::string& sprite : sprites) {
		std::cout << "creating " << sprite << " surface" << std::endl;
		std::string location = path + "/sprites/" + sprite;
		sf::Texture texture;
		texture.setSmooth(true);
		if (!texture.loadFromFile(location))
		{
			std::cout << "Unable to load " << sprite << std::endl;
		}
		sf::Sprite Sprite;
		Sprite.setTextureRect({ 0, 0, CELL_SIZE, CELL_SIZE });
		vector_sprites.push_back(Sprite);
		vector_textures.push_back(texture);
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
		if (vector_sprites[index].getTexture() != &vector_textures[index]) vector_sprites[index].setTexture(vector_textures[index]);
		return vector_sprites[index];
	}
}
