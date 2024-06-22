#pragma once
#include <vector>
#include "Vector2.h"
#include "GameObject.h"

class GameObject;
class PhysicsEngine
{
public:
	PhysicsEngine(Vector2 gravity);
	PhysicsEngine();
	void applyForce();
	void addObject(GameObject* gameobject);
	~PhysicsEngine();
private:
	std::vector<GameObject*> gameObjects;
	Vector2 gravity;
};

