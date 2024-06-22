#include<iostream>
#include <SFML/Graphics.hpp>
#include "PhysicsEngine.h"
#include "GameObject.h"
#include "Block.h"

using namespace std;

void main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    window.setFramerateLimit(60);
    PhysicsEngine engine;
    vector<GameObject*> gameObjects;
    const float timeStep = 1.0f / 60.0f;
    sf::Clock clock;
    float accumulator = 0.0f;
    Block* block = new Block();
    block->loadTexture("block.png");
    block->setImmovable(false);
    gameObjects.push_back(block);
    vector<Block*> ground;
    for (int i = 0; i < 25; ++i)
    {
        Block* block = new Block();
        block->loadTexture("block.png");
        block->setImmovable(true);
        block->getSprite().setPosition(i * 32, 500);
        ground.push_back(block);
        engine.addObject(block);
        gameObjects.push_back(block);
    }
    engine.addObject(block);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float deltaTime = clock.restart().asSeconds();
        accumulator += deltaTime;

        while (accumulator >= timeStep) {
            window.clear();
            
            engine.applyForce();
            for (auto i : gameObjects)
            {
                if (block != i && block->isColliding(*i))
                {
                    block->setImmovable(true);
                }
                i->update(timeStep);
                i->render(window);
            }

            window.display();

            accumulator -= timeStep;
        }
    }
}