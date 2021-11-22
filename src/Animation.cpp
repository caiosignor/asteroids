#include "../inc/Animation.h"
#include <iostream>

Animation::Animation()
{
}


Animation::Animation(std::string textureFileName, int x, int y, int w, int h, int count, float Speed)
{
    Frame = 0;
    speed = Speed;
    if(!this->texture.loadFromFile(textureFileName))
        std::cout << "Error loading texture" << std::endl;
    
    this->sprite = sf::Sprite(this->texture);

    for (int i = 0; i < count; i++)
        frames.push_back(sf::IntRect(x + i * w, y, w, h));

    sprite.setTexture(this->texture);
    sprite.setOrigin(w / 2, h / 2);
    sprite.setTextureRect(frames[0]);
}

sf::Sprite Animation::update()
{
    Frame += speed;
    int n = frames.size();
    if (Frame >= n)
        Frame -= n;
    if (n > 0)
        sprite.setTextureRect(frames[int(Frame)]);
    /*
    sprite.setTextureRect(frames[0]);

        */
    return sprite;
}

bool Animation::isEnd()
{
    return Frame + speed >= frames.size();
}
