#include "MissileCollisions.h"

void MissileCollision:: MissileCollisions()
{
   for(auto Iter=missile.Missiles.begin();Iter<missile.Missiles.end();Iter++)
    {
        if(MissileShipCollision((*(*Iter)),*(*spaceship.TheShip.begin())))
        {
            missile.Missiles.erase(Iter);
            gamestatus.Loss();
            scoresystem.UpdateHighestScore();
        }

        if(MissileScreenCollision((*(*Iter))))
        {
          missile.Missiles.erase(Iter);
        }

    }

}

bool MissileCollision:: MissileShipCollision(MobileObject& Themissile,MobileObject& Theship)
{
   
 auto Collision=false;
      if(!spaceship.isInvulnerable && ObjectToObjectCollision(Themissile,Theship))
      {
        Collision=true;
     
      }   
    return Collision;
}

bool MissileCollision:: MissileScreenCollision(MobileObject&TheMissile)
{
  auto Collision=false;

    if(ScreenCollision(TheMissile))
    {
      Collision=true;
    }

  return Collision;

}
