#ifndef COLLISIONBASE
#define COLLISIONBASE

#include "MobileObject.h"
#include "Dimensions.h"

class CollisionsBase
{
    public:
       virtual bool ObjectToObjectCollision(MobileObject& collided,MobileObject& colliding);
       virtual bool ScreenCollision(MobileObject& colliding);
    protected:
    Dimensions dimensions;

};


#endif
