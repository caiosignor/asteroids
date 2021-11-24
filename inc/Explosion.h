#include <SFML/Graphics.hpp>
#include "Entity.h"

class Explosion : public Entity
{
private:
    int x_limit, y_limit, speed_limit, speed;
    bool thrust;
    void update_position();

public:
    Explosion();
    Explosion(float x, float y);
    Explosion(sf::Texture t, sf::Sprite s, float x, float y);
    Explosion(int x_limit, int y_limit, float speed_limit);
    sf::Sprite draw();
};