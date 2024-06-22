#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine(Vector2 gravity)
{
	this->gravity = gravity;
}

PhysicsEngine::PhysicsEngine()
{
	Vector2 gravity(0, 9.8f);
	this->gravity = gravity;
}

PhysicsEngine::~PhysicsEngine()
{
	for (auto i : gameObjects)
	{
		delete i;
	}
}

void PhysicsEngine::addObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject);
}

void PhysicsEngine::applyForce()
{
	for (auto i : gameObjects)
	{
		i->applyForce(gravity);
	}
}