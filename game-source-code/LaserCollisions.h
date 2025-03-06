#ifndef LASERCOLLISIONS
#define LASERCOLLISIONS

#include <algorithm>
#include <iostream>

#include "MobileObject.h"
#include "Laser.h"
#include "Missile.h"
#include "Humanoid.h"
#include "Lander.h"
#include "ScoringSystem.h"
#include "GameStatus.h"

#include "CollisionsBase.h"

using namespace std;

class LaserCollision:public CollisionsBase
{
    public:
        void LaserCollisions();
    
        bool BulletScreenCollision(MobileObject&bullet);
        bool BulletMissileCollision(Laser&bullet,Missile&TheMissile);
        bool BulletLanderCollision(Laser&bullet,Lander&TheLander);
        bool BulletHumanoidCollision(Laser&bullet,Lander&TheHumanoid);

        private:
        Missile missile;
        Lander lander;
        Laser laser;
        Humanoid humanoid;
        ScoringSystem scoresystem;
        GameStatus gamestatus;
        void EraseObjectFromLaser(vector<Laser>&BulletVector,MobileObject&bullet);


    


};






#endif