#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
public:
   float Frame, speed;
   sf::Texture texture;
   sf::Sprite sprite;
   std::vector<sf::IntRect> frames;

   Animation();

   Animation(std::string textureFileName, int x, int y, int w, int h, int count, float Speed);
   Animation(sf::Texture texture, sf::Sprite sp, int x, int y, int w, int h, int count, float Speed);
   sf::Sprite update();
   bool isEnd();
};

#endif