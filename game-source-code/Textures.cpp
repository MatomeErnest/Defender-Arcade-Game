#include "Textures.h"
Textures::Textures()
{
  
}
sf::Texture* Textures::getLander()
{
    Lander_.loadFromFile("resources/Lander.png");
    return &Lander_;
}
sf::Texture* Textures::getSpaceShip()
{
    SpaceShip_.loadFromFile("resources/Spaceship.png");
    return &SpaceShip_;
}
sf::Texture* Textures::getMissile()
{
    Missile_.loadFromFile("resources/Missile.png");
    return &Missile_;
}

sf::Texture* Textures::getBullet()
{
    bullet.loadFromFile("resources/bullet1.png");
    return &bullet;
}

sf::Texture* Textures::getIntroTexture()
{
    IntroSplash.loadFromFile("resources/Splashbackground.jpg");
    return &IntroSplash;
}
sf::Texture* Textures:: getHumanoidTexture()
{
   Humanoid.loadFromFile("resources/Humanoid.png");
  
    return &Humanoid;
}

sf::Texture* Textures:: GasPumpTexture()
{
    if(!GasPump.loadFromFile("resources/GasPump.png"))
    {
        cout <<"Not uploaded"<<endl;
    }

    return &GasPump;
}