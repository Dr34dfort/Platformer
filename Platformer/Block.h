#pragma once
#include "GameObject.h"
class Block :
    public GameObject
{
public:
    Block();
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    void loadTexture(std::string path) override;
    void setSprite() override;
};

