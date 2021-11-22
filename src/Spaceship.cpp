#include "../inc/Spaceship.h"
#include <math.h>
#include <iostream>

Spaceship::Spaceship(){

};

Spaceship::Spaceship(std::string texture_path, int x_limit, int y_limit, int speed_limit) : x_limit(x_limit), y_limit(y_limit), speed_limit(speed_limit)
{
    Entity::name = "spaceship";
    this->cadence = 15;
    this->anim = new Animation(texture_path, 40, 0, 40, 40, 1, 0);
    this->thrust = false;
};

void Spaceship::update_position()
{
    float accelaration = 0.2;
    float deaccelaration = 0.99;

    if (thrust)
    {
        Entity::dx += accelaration * cos(angle * M_PI / 180.0);
        Entity::dy += accelaration * sin(angle * M_PI / 180.0);
    }
    else
    {
        Entity::dx *= deaccelaration;
        Entity::dy *= deaccelaration;
    }

    Entity::x += Entity::dx;
    Entity::y += Entity::dy;

    float speed = sqrt(Entity::dx * Entity::dx + Entity::dy * Entity::dy);

    if (speed > speed_limit)
    {
        Entity::dx *= speed_limit / speed;
        Entity::dy *= speed_limit / speed;
    }

    if (Entity::x > x_limit)
        Entity::x = x_limit;
    if (Entity::x < 0)
        Entity::x = 0;
    if (Entity::y > y_limit)
        Entity::y = y_limit;
    if (Entity::y < 0)
        Entity::y = 0;
}

sf::Sprite Spaceship::draw()
{
    update_position();

    return Entity::display();
}

void Spaceship::incAngle()
{
    angle += 5;
}

void Spaceship::decAngle()
{
    angle -= 5;
}

void Spaceship::throttleFull()
{
    thrust = true;
}

void Spaceship::throttleRelease()
{
    thrust = false;
}

Bullet *Spaceship::shoot()
{
    this->cadence = 15;
    return new Bullet(Entity::x, Entity::y, Entity::angle, x_limit, y_limit);
}

void Spaceship::cadenceDown()
{
    if (this->cadence > 0)
        this->cadence--;
}

bool Spaceship::availableToShot()
{
    if (this->cadence <= 0)
        return true;
    return false;
}