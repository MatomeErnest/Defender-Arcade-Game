#ifndef HUMANOID_H
#define HUMANOID_H


#include "MobileObject.h"
#include "SpaceShip.h"
#include <iostream>
#include <memory>
#include <cmath>

using namespace std;

class HumanoidCannotMoveHozintally{};

class Humanoid: public MobileObject
{

    public:
        Humanoid();
        virtual void MoveLeft() override;
        virtual void MoveRight() override;

        virtual void CreateObject() override;
        virtual void MoveObject() override;

        void followShip();

        void ResetHumanoidStatus();

        void ResetHumanoids();

        static vector<shared_ptr<Humanoid>> Humanoids;
        bool freed=false;
        bool PickedByLander=false;
        bool Targeted=false;
        int LanderIndex;
        bool comparable=true;

        bool FollowShip=false;

        
    private:
        static sf::Vector2f HumanoidPosition;
        float HumanoidSpeed=2.f;
        float ShipSpeed=65.f;
        sf::Vector2f humanoidDirection;
        SpaceShip spaceship;
        sf::Vector2f HumanoidInitialPosition;
        

};

#endif




