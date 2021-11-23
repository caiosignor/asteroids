#include "../inc/Entity.h"
#include <iostream>
Entity::Entity()
{
    life = 1;
};

sf::Sprite Entity::display()
{
    this->anim->sprite.setPosition(x, y);
    this->anim->sprite.setRotation(angle + 90);
    return this->anim->update();
}

bool Entity::collision(Entity *e)
{
    return (this->x - e->x) * (this->x - e->x) + (this->y - e->y) * (this->y - e->y) < (this->R + e->R)*(this->R + e->R);
}