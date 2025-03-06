#ifndef MISSILE_H
#define MISSILE_H


#include "Textures.h"
#include "SpaceShip.h"
#include <iostream>
#include <tuple>
#include <cmath>
#include <memory>

using namespace std;


class Missile:public MobileObject
{
    public:
        Missile();
        Missile(sf::Vector2f ShipPosition,sf::Vector2f LanderPosition);
        virtual void CreateObject() override;
        virtual void MoveObject() override;

        static vector<shared_ptr<Missile>>Missiles;
    private:
        
        sf::Vector2f ShipPosition_;
        sf::Vector2f MissilePosition_;
        const float MissileSpeed=4.f;
        sf::Vector2f direction;
       
};

#endif