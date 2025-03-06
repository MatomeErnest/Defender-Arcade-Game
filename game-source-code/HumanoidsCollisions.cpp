#include "HumanoidsCollisions.h"

bool HumanoidCollision:: IsHumanoidScreenCollision(Humanoid&Thehumanoid)
{
    auto IsCollision=false;
        auto humanoidPosition=Thehumanoid.TheSprite()->getPosition().y;
      if((humanoidPosition>832.f||humanoidPosition<110)&&!Thehumanoid.FollowShip)//while dropping
      {
        IsCollision=true;
       
      }else if(humanoidPosition>832.f&&Thehumanoid.FollowShip)//while carried by ship
      {
        IsCollision=true;
        
      }

return IsCollision;

}

void HumanoidCollision:: HumanoidCollisions()
{
    for(auto Iter=humanoid.Humanoids.begin();Iter<humanoid.Humanoids.end();Iter++)
    {
        if(IsHumanoidScreenCollision((*(*Iter)))&&!(*Iter)->FollowShip)
        {
            if(humanoid.Humanoids.size()==1)
            {
                gamestatus.Loss();
            }
            humanoid.Humanoids.erase(Iter);
        }else if(IsHumanoidScreenCollision((*(*Iter))),(*Iter)->FollowShip)
        {
            (*Iter)->ResetHumanoidStatus();

        }

    }

}




