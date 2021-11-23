#include "../inc/Asteroid.h"
#include <math.h>

Asteroid::Asteroid()
{
}

Asteroid::Asteroid(float x, float y, int x_limit, int y_limit) : x_limit(x_limit), y_limit(y_limit)
{
    Entity::x = x;
    Entity::y = y;
    Entity::dx = rand() % 8 - 4;
    Entity::dy = rand() % 8 - 4;
    Entity::angle = rand() % 360;
    Entity::anim = new Animation("../images/rock.png", 0, 0, 64, 64, 16, 15);
    Entity::name = "asteroid";
    this->speed = 25;
}

sf::Sprite Asteroid::draw()
{
    Entity::x += dx;
    Entity::y += dy;

    if (x > x_limit || x < 0 || y > y_limit || y < 0)
        life = 0;

    return Entity::display();
}
