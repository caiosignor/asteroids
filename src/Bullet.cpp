#include "../inc/Bullet.h"
#include <math.h>

Bullet::Bullet()
{
}

Bullet::Bullet(float x, float y, float angle, int x_limit, int y_limit) : x_limit(x_limit), y_limit(y_limit)
{
    Entity::x = x;
    Entity::y = y;
    Entity::angle = angle;
    Entity::anim = new Animation("../images/fire_blue.png", 0, 0, 32, 64, 16, 15);
    Entity::name = "bullet";
}

sf::Sprite Bullet::draw()
{
    Entity::dx = cos(angle * M_PI / 180) * 6;
    Entity::dy = sin(angle * M_PI / 180) * 6;
    Entity::x += dx;
    Entity::y += dy;

    if (x > x_limit || x < 0 || y > y_limit || y < 0)
        life = 0;
    
    return Entity::display();
}
