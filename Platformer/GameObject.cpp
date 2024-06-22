#include "GameObject.h"

void GameObject::applyForce(Vector2 force)
{
	if (!getImmovable())
	{
		acceleration.x += force.x / mass;
		acceleration.y += force.y / mass;
	}
	else
	{
		setVelocity(0, 0);
		setAcceleration(0, 0);
	}
}

void GameObject::applyForce(float x, float y)
{
	if (!getImmovable())
	{
		acceleration.x += x / mass;
		acceleration.y += y / mass;
	}
	else
	{
		setVelocity(0, 0);
		setAcceleration(0, 0);
	}
}

bool GameObject::isColliding(const GameObject& object) 
{ 
	if (this->sprite.getGlobalBounds().intersects(object.sprite.getGlobalBounds()))
	{
		//this->applyForce(-this->getAcceleration().x * this->getMass(), -this->getAcceleration().y * this->getMass());
		if (this->getSprite().getPosition().y < object.sprite.getPosition().y)
			this->getSprite().setPosition(this->getSprite().getPosition().x, object.sprite.getPosition().y - this->getSprite().getGlobalBounds().height);
		else if (this->getSprite().getPosition().y > object.sprite.getPosition().y + object.sprite.getGlobalBounds().height)
			this->getSprite().setPosition(this->getSprite().getPosition().x, object.sprite.getPosition().y + this->getSprite().getGlobalBounds().height);
		return true;
	}
	return false; 
}