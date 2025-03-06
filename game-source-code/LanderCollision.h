#ifndef LANDERCOLLISION
#define LANDERCOLLISION

#include "CollisionsBase.h"
#include "Humanoid.h"
#include "Lander.h"

class LanderCollision:public CollisionsBase
{

    public:
        void LanderCollisions();
        void LanderScreenCollision(Lander&TheLander);
        void LanderHumanoidCollision(Lander&TheLander, Humanoid&TheHumanoid);
    
    private:
    Lander lander;
    Humanoid humanoid;

};



#endif