#include "../inc/Bullet.h"
#include <math.h>

Bullet::Bullet()
{
}

Bullet::Bullet(float x, float y, float angle, int x_limit, int y_limit, int speed) : x_limit(x_limit), y_limit(y_limit), speed(speed)
{
    Entity::x = x;
    Entity::y = y;
    Entity::angle = angle;
    Entity::anim = new Animation("../images/fire_blue.png", 0, 0, 32, 64, 16, 15);
    Entity::name = "bullet";
    Entity::R = 10;
}

sf::Sprite Bullet::draw()
{
    Entity::dx = cos(angle * M_PI / 180) * 10;
    Entity::dy = sin(angle * M_PI / 180) * 10;
    Entity::x += dx+speed;
    Entity::y += dy+speed;

    if (x > x_limit || x < 0 || y > y_limit || y < 0)
        life = 0;
    
    return Entity::display();
}
