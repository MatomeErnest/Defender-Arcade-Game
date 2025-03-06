#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "MobileObject.h"
#include "Directions.h"
#include "Laser.h"

#include "Dimensions.h"
#include <memory>
#include <iostream>

using namespace std;

class SpaceShip:public MobileObject
{
    public:
        SpaceShip();
        void TurnLeft();
        void TurnRight();
        void Shoot();
        void setShipInvulnerable();
        void OriginalColor();
        Directions shipdirection();
        virtual void MoveObject() override;
        virtual void CreateObject() override;
        virtual void MoveLeft() override;
        virtual void MoveRight() override;
        virtual void MoveUp() override;
        virtual void MoveDown() override;
        void ResetShipStatus();

        static Directions shipdirection_; 
        static  Directions shipglobaldirection;
        static vector<shared_ptr<SpaceShip>> TheShip;
        static bool ShipMovedRight;
        static bool ShipMovedLeft;
        static bool OutOfFuel;

        static bool IsSaving;

        static bool ShipMoved;

        static bool isInvulnerable;

    private:
       
        float ShipSpeed=65.f; 
        const float FallingShipSpeed=2.f;
        bool isSpaceShipTurnedLeft=false;
        Laser laser;
        Dimensions dimensions;
        
};

#endif