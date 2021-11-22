#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
class Entity
{
private:
public:
    float x, y, dx, dy, angle;
    bool life;
    std::string name;
    Animation *anim;
    Entity();
    virtual ~Entity(){};
    sf::Sprite display();
};

#endif