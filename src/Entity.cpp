#include "../inc/Entity.h"

Entity::Entity()
{
    life = 1;
};

sf::Sprite Entity::display()
{
    this->anim->sprite.setPosition(x, y);
    this->anim->sprite.setRotation(angle + 90);
    return this->anim->update();

//    return this->anim.sprite;
}