#pragma once
#include "PhysicsEngine.h"
#include "Vector2.h"
#include <SFML/Graphics.hpp>
#include <string>

class GameObject
{
public:
	virtual void update(float deltaTime) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual bool getImmovable() { return immovable; }
	virtual Vector2& getVelocity() { return velocity; }
	virtual Vector2& getAcceleration() { return acceleration; }
	virtual void setAcceleration(Vector2 accel) { acceleration = accel; }
	virtual void setAcceleration(float x, float y) { acceleration.x = x; acceleration.y = y; }
	virtual void setVelocity(Vector2 vel) { velocity = vel; }
	virtual void setVelocity(float x, float y) { velocity.x = x; velocity.y = y; }
	virtual void applyForce(Vector2 force);
	virtual void applyForce(float x, float y);
	virtual void setImmovable(bool immovable) { this->immovable = immovable; }
	virtual void loadTexture(std::string path) = 0;
	virtual void setSprite() = 0;
	virtual void setMass(float mass) { this->mass = mass; }
	virtual float getMass() { return mass; }
	virtual sf::Sprite& getSprite() { return sprite; }
	virtual bool isColliding(const GameObject& object);
private:
	float mass;
	Vector2 velocity;
	Vector2 acceleration;
	bool immovable;
protected:
	sf::Sprite sprite;
	sf::Texture texture;
};

