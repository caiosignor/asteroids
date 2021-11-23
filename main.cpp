#include <SFML/Graphics.hpp>
#include <math.h>
#include "inc/Spaceship.h"
#include "inc/Animation.h"
#include "inc/Entity.h"
#include <list>
#include <iostream>

const int WIDTH = 1200;
const int HEIGHT = 800;

Spaceship *spaceship = new Spaceship("../images/spaceship.png", WIDTH - 10, HEIGHT - 10, 15);
std::list<Entity *> entities;

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

    sf::Texture tBackground;

    tBackground.loadFromFile("../images/background.jpg");

    sf::Sprite sBackground(tBackground);

    entities.push_back(spaceship);

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
        
        for (auto i = entities.begin(); i != entities.end();)
        {
            Entity *entity = *i;
            if (!entity->life)
            {
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
        }

        spaceship->cadenceDown();
        window.display();
    }

    return 0;
}