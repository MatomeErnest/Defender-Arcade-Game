#ifndef LASER_H
#define LASER_H

#include <SFML/Graphics.hpp>
#include  "Directions.h"
#include "MobileObject.h"
#include <iostream>
#include <memory>

using namespace std;

class BulletDoesntMoveVertical{};
class Laser:public MobileObject
{
public:
    Laser();
    Laser(sf::Vector2f,Directions);
    virtual void MoveUp() override;
    virtual void MoveDown() override;
    virtual void CreateObject() override;
    virtual void MoveObject() override;
    
    static vector <shared_ptr<Laser>>bulletsvector;
private:

    float BulletSpeed=50.f;
    Directions BulletDirection;
    sf::Sprite bullet;
    sf::Vector2f DirectionVector;

    sf::Vector2f ShipPosition_;
    Directions shipdirection_;
    
};

#endif