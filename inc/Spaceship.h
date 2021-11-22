#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Bullet.h"

class Spaceship : public Entity
{
private:
    int x_limit, y_limit, speed_limit;
    bool thrust;
    void update_position();

public:
    Spaceship();
    Spaceship(std::string texture_path, int x_limit, int y_limit, int speed_limit);
    sf::Sprite draw();
    void incAngle();
    void decAngle();
    void throttleFull();
    void throttleRelease();
    Bullet* shoot();
};