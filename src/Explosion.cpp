#include "../inc/Explosion.h"
#include <math.h>

Explosion::Explosion()
{
}

Explosion::Explosion(float x, float y)
{
    Entity::x = x;
    Entity::y = y;
    Entity::angle = angle;
    Entity::anim = new Animation("../images/explosions/type_C.png", 0, 0, 256, 256, 48, 0.5);
    Entity::name = "explosion";
    Entity::R = 10;
}

Explosion::Explosion(sf::Texture t, sf::Sprite s, float x, float y)
{
    Entity::x = x;
    Entity::y = y;
    Entity::angle = angle;
    Entity::anim = new Animation(t, s, 0, 0, 256, 256, 48, 0.5);
    Entity::name = "explosion";
    Entity::R = 10;
}

sf::Sprite Explosion::draw()
{
    if (Entity::anim->isEnd())
    {
        Entity::life = 0;
    }
    return Entity::display();
}
