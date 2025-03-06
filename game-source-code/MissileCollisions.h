#ifndef MISSILECOLLISION_H
#define MISSILECOLLISION_H

#include "CollisionsBase.h"
#include "SpaceShip.h"
#include "ScoringSystem.h"
#include "GameStatus.h"
#include "Missile.h"

class MissileCollision:public CollisionsBase
{
    public:
        void MissileCollisions();
        bool MissileShipCollision(MobileObject& Themissile,MobileObject& Theship);
        bool MissileScreenCollision(MobileObject&Themissile);
    private:
    SpaceShip spaceship;
    ScoringSystem scoresystem;
    GameStatus gamestatus;
    Missile missile;
        


};




#endif