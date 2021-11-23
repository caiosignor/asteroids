#include <SFML/Graphics.hpp>
#include "Entity.h"

class Asteroid : public Entity
{
private:
    int x_limit, y_limit, speed_limit, speed;
    bool thrust;
    void update_position();

public:
    Asteroid();
    Asteroid(float x, float y, int x_limit, int y_limit);
    Asteroid(int x_limit, int y_limit, float speed_limit);
    sf::Sprite draw();
};