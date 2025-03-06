#include "LanderCollision.h"

void LanderCollision:: LanderCollisions()
{
    for(auto Iter=lander.landers.begin();Iter<lander.landers.end();Iter++)
    {
        LanderScreenCollision((*(*Iter)));

        LanderHumanoidCollision((*(*Iter)),*((*Iter)->Target));

        
    }

}
void LanderCollision:: LanderScreenCollision(Lander&TheLander)
{

    if(ScreenCollision(TheLander)&&!TheLander.HasCaptured&&!TheLander.HasTarget)
    {

      TheLander.ChangeLanderDirection();
      
      
    }else if (TheLander.TheSprite()->getPosition().y<110&&TheLander.HasCaptured&&TheLander.HasTarget)
    {
      TheLander.HasCaptured=false;
      TheLander.HasTarget=false;
      TheLander.ChangeLanderDirection();
    }

}
void LanderCollision:: LanderHumanoidCollision(Lander&TheLander, Humanoid&TheHumanoid)
{
   // auto Collision=false;
    if(TheLander.HasTarget)
    {

      if(ObjectToObjectCollision(TheHumanoid,TheLander))
      {
        //Collision=true;
        TheLander.Target->PickedByLander=true;
        TheLander.HasCaptured=true; 
      }
    }
    //return Collision;

}
