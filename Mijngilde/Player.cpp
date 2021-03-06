#include <iostream>
#include "Player.h"

Player::Player(std::string name) {
	this->name = name;
	player = { 0, 0, 115, 430 }; // Sprite texture sizes
}

std::string Player::getName() {
	return name;
}

void Player::setSprite(sf::Sprite sprite) {
	playerSprite = sprite;
    playerSprite.setTextureRect(player);
	playerSprite.setScale(playerWidth / playerSprite.getLocalBounds().width, playerHeight / playerSprite.getLocalBounds().height);
	player.width = playerWidth;
	player.height = playerHeight;
}

void Player::doDamage() {
	// Do damage
}

void Player::move(std::string direction, bool collide) {
	Player::direction = direction;
	if (direction == "left") player.left -= speed;
	else if (direction == "right") player.left += speed;
	if (!collide) {
		if (direction == "left") {
			playerSprite.setScale((-playerWidth) / playerSprite.getLocalBounds().width, playerHeight / playerSprite.getLocalBounds().height);
			player.width = -playerWidth;
		}
		else if (direction == "right") {
			playerSprite.setScale(playerWidth / playerSprite.getLocalBounds().width, playerHeight / playerSprite.getLocalBounds().height);
			player.width = playerWidth;
		}
	}
}

void Player::setPosition(int x, int y) {
    player.left = x, player.top = y;
    playerSprite.setPosition(sf::Vector2f(player.left, player.top));
}

sf::Sprite Player::getPlayer() {
	return playerSprite;
}

sf::IntRect Player::getPlayerRect() {
	return player;
}

std::string Player::getPlayerDirection() {
	return Player::direction;
}