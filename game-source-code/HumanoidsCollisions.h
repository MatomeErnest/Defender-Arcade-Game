#ifndef HUMANOIDCOLLISION
#define HUMANOIDCOLLISION
#include "GameStatus.h"
#include "Humanoid.h"

class HumanoidCollision
{
    public:
        bool IsHumanoidScreenCollision(Humanoid&Thehumanoid);
        void HumanoidCollisions();
    private:
        Humanoid humanoid;
        GameStatus gamestatus;

};



#endif