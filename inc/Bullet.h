#include <SFML/Graphics.hpp>
#include "Entity.h"

class Bullet : public Entity
{
private:
    int x_limit, y_limit, speed_limit, speed;
    bool thrust;
    void update_position();

public:
    Bullet();
    Bullet(float x, float y, float angle, int x_limit, int y_limit, int speed);
    Bullet(int x_limit, int y_limit, float speed_limit);
    sf::Sprite draw();
};