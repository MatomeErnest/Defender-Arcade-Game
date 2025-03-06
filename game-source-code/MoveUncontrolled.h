#ifndef MOVEUNCONTROLLED_H
#define MOVEUNCONTROLLED_H

#include <iostream>
#include <algorithm>
#include "GameCollisions.h"
#include "Lander.h"
#include "SpaceShip.h"
//#include "MobileObject.h"


using namespace std;
using MobileObjectVector=vector<shared_ptr<MobileObject>>;

class MoveUncontrolled
{
    public:
        MoveUncontrolled();

        void MoveObjects();

        void MoveBullets(Laser&TheLaser);
        void MoveLanders(Lander&TheLander);
        void MoveMissiles(Missile&TheMissile);
        void MoveHumanoids(Humanoid&TheHumanoids);
        void MovemAmmunition();
        void MoveEnemies();

        void MoveMobileObjects(MobileObject& mobileobjects);
        

        static sf::Clock shipclock;
    private:
        GameCollisions collisions;
        Laser laser;
        Lander lander;
        SpaceShip spaceship;
        Missile missiles;
        Humanoid humanoid;

        
        sf::Time T1=sf::seconds(4.f);
        float ShipDelay;
    
        static sf::Clock clock;
        sf::Time T=sf::seconds(3.f);
        float AttackingDelay;       

};

#endif