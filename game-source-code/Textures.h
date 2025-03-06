#ifndef TEXTURES_H
#define TEXTURES_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <tuple>
#include <vector>
using namespace std;
class Textures
{
    public:
     Textures();
     sf::Texture* getLander();
     sf::Texture* getSpaceShip();
     sf::Texture* getMissile();
     sf::Texture* getBullet();
     sf::Texture* getIntroTexture();
     sf::Texture* getHumanoidTexture();
     sf::Texture* GasPumpTexture();
    private:
     sf:: Texture Lander_;
     sf::Texture SpaceShip_;
     sf::Texture Missile_;
     sf::Texture bullet;
     sf::Texture IntroSplash;
     sf::Texture Humanoid;
     sf::Texture GasPump;
     vector<sf::Texture>laser_;
};

#endif