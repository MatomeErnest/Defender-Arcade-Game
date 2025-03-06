#ifndef GAMECOLLISIONS_H
#define GAMECOLLISIONS_H

#include "ShipCollisions.h"
#include "LanderCollision.h"
#include "MissileCollisions.h"
#include "LaserCollisions.h"
#include "HumanoidsCollisions.h"
#include <algorithm>



class GameCollisions
{
    public:
    
        void CheckCollisions();

//////////////////////////////////////////////////////////////////////////////  
    private:       

        ShipCollisionDetections shipcollision;
        LanderCollision landercollision;
        MissileCollision missilecollision;
        LaserCollision lasercollision;
        HumanoidCollision humanoidcollision;



};
#endif