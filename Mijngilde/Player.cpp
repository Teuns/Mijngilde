#include <iostream>
#include "Player.h"
#include "Game.h"

Player::Player(std::string name) {
	this->name = name;
	player = { 0, 0, 115, 430 };
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

void Player::move(std::string direction) {
	if (direction == "left") player.left -= speed;
	else if (direction == "right") player.left += speed;
    // playerSprite.setPosition(sf::Vector2f(player.left, player.top));
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