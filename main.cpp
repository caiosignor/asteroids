#include <SFML/Graphics.hpp>
#include <math.h>
#include "inc/Spaceship.h"
#include "inc/Animation.h"
#include "inc/Entity.h"
#include "inc/Asteroid.h"
#include "inc/Explosion.h"
#include <list>
#include <iostream>
const int WIDTH = 1200;
const int HEIGHT = 800;

Spaceship *spaceship = new Spaceship("../images/spaceship.png", WIDTH - 10, HEIGHT - 10, 15);
std::list<Entity *> entities;

void createAsteroid()
{
    entities.push_back(new Asteroid(rand() % WIDTH, rand() % HEIGHT, WIDTH, HEIGHT));
}

void handleInputEvents()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        spaceship->incAngle();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        spaceship->decAngle();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && spaceship->availableToShot())
        entities.push_back(spaceship->shoot());
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        spaceship->throttleFull();
    else
        spaceship->throttleRelease();
}

int main()
{
    // Create a window

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Asteroids");
    window.setFramerateLimit(60);

    sf::Texture tBackground, tExplosion;

    tBackground.loadFromFile("../images/background.jpg");
    tExplosion.loadFromFile("../images/explosions/type_C.png");

    sf::Sprite sBackground(tBackground), sExplosion(tExplosion);

    entities.push_back(spaceship);

    for (int i = 0; i < 15; i++)
        createAsteroid();

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        handleInputEvents();

        window.clear();
        window.draw(sBackground);

        for (auto a : entities)
        {
            for (auto b : entities)
            {
                if (a->name == "bullet" && b->name == "asteroid")
                {
                    if (a->collision(b))
                    {
                        a->life = false;
                        b->life = false;
                        entities.push_back(new Explosion(tExplosion, sExplosion, a->x, b->y));
                    }
                }
            }
        }

        for (auto i = entities.begin(); i != entities.end();)
        {
            Entity *entity = *i;
            if (!entity->life)
            {
                if (entity->name == "asteroid")
                    createAsteroid();
                i = entities.erase(i);
            }
            else
                i++;
        }

        for (auto ent : entities)
        {
            if (ent->name == std::string("spaceship"))
            {
                Spaceship *spaceship = (Spaceship *)ent;
                window.draw(spaceship->draw());
            }
            if (ent->name == std::string("bullet"))
            {
                Bullet *bullet = (Bullet *)ent;
                window.draw(bullet->draw());
            }
            if (ent->name == std::string("asteroid"))
            {
                Asteroid *asteroid = (Asteroid *)ent;
                window.draw(asteroid->draw());
            }
            if (ent->name == std::string("explosion"))
            {
                Explosion *explosion = (Explosion *)ent;
                window.draw(explosion->draw());
            }
        }

        spaceship->cadenceDown();
        window.display();
    }

    return 0;
}