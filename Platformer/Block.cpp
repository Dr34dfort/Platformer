#include "Block.h"

Block::Block()
{
	setMass(1);
}

void Block::update(float deltaTime)
{
	setVelocity(getVelocity().x + getAcceleration().x * deltaTime, getVelocity().y + getAcceleration().y * deltaTime);

	sprite.setPosition(sprite.getPosition().x + getVelocity().x * deltaTime, sprite.getPosition().y + getVelocity().y * deltaTime);

}

void Block::render(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Block::loadTexture(std::string path)
{
	texture.loadFromFile(path);
	setSprite();
}

void Block::setSprite()
{
	sprite.setTexture(texture);
}