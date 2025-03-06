#include "LaserCollisions.h"

void LaserCollision:: LaserCollisions()
{
    for(auto Iter=laser.bulletsvector.begin();Iter<laser.bulletsvector.end();Iter++)
    {
        if(BulletScreenCollision((*(*Iter))))
        {
            laser.bulletsvector.erase(Iter);
        }

        ///////////////////////////////////////////Bullet and Missiles////////
        for(auto Iter1=missile.Missiles.begin();Iter1<missile.Missiles.end();Iter1++)
        {
            if(BulletMissileCollision(*(*Iter),(*(*Iter1))))
            {

                missile.Missiles.erase(Iter1);
                scoresystem.IncrementScore(10.f);
                laser.bulletsvector.clear();
                break;
            }
        }
        //////////////////////////////////////////////Bullet and Lander/////////////////////
        for(auto Iter2=lander.landers.begin();Iter2<lander.landers.end();Iter2++)
        {
            if(BulletLanderCollision((*(*Iter)),(*(*Iter2))))
            {
                lander.landers.erase(Iter2);

                if(lander.landers.empty()&&gamestatus.gameplay&&lander.NumberofLanders==5)
                {
                    gamestatus.Victory();
                }

                scoresystem.IncrementScore(20.f);
                laser.bulletsvector.clear();
                break;

            }
        }
         //////////////////////////////////////////////Bullet and Humanoid-/////////////////////
        for(auto Iter3=lander.landers.begin();Iter3<lander.landers.end();Iter3++)
        {

           if(BulletHumanoidCollision((*(*Iter)),(*(*Iter3))))
           {

                laser.bulletsvector.clear();
                break;

           }

        }
    }

}


bool LaserCollision:: BulletScreenCollision(MobileObject&bullet)
{
    auto Collision=false;
      if(ScreenCollision(bullet))
      {
        Collision=true;
       
      }   
    
    return Collision;
}
bool LaserCollision::BulletMissileCollision(Laser&bullet,Missile&TheMissile)
{
     auto BulletCollision=false;
 

    if(ObjectToObjectCollision(TheMissile,bullet))
    {

      BulletCollision=true;
    }
  
  
  return BulletCollision;

}

bool LaserCollision:: BulletLanderCollision(Laser&bullet,Lander&TheLander)
{
    auto BulletCollision=false;
    auto M1=bullet.TheSprite()->getGlobalBounds();


        auto N1=TheLander.TheSprite()->getGlobalBounds();
    
        if(M1.intersects(N1)&&!TheLander.HasTarget)//before having a target
        {
            //lander.landers.erase(Iter);
            
            BulletCollision=true;
            // if(lander.landers.empty()&&gamestatus.gameplay&&lander.NumberofLanders==5)
            // {
            //     gamestatus.Victory();
            // }

        }else if(M1.intersects(N1)&&!TheLander.HasCaptured&&TheLander.HasTarget)//Before it reaching the hamanoid
        {
      
     
            //Make humanoid pointed free(untargeted)
            TheLander.Target->Targeted=false;
       
            // lander.landers.erase(Iter);
            
      
            BulletCollision=true;
            // if(lander.landers.empty()&&gamestatus.gameplay&&lander.NumberofLanders==5)
            // {
            //     gamestatus.Victory();
            // }

        }else if(M1.intersects(N1)&&TheLander.HasCaptured&&TheLander.HasTarget)
        {
            TheLander.Target->PickedByLander=false;
      
            TheLander.Target->freed=true;

            // lander.landers.erase(Iter);
            
            BulletCollision=true;

            // if(lander.landers.empty()&&gamestatus.gameplay&&lander.NumberofLanders==5)
            // {
            //     gamestatus.Victory();
            // }
        }
  
    
return BulletCollision;

}
bool LaserCollision:: BulletHumanoidCollision(Laser&bullet,Lander&TheLander)
{

    auto BulletCollision=false;
    auto B=bullet.TheSprite()->getGlobalBounds();
  

        if(TheLander.HasTarget)
        {
            auto H=TheLander.Target->TheSprite()->getGlobalBounds();
            if(B.intersects(H)&&TheLander.Target->PickedByLander&&TheLander.Target->Targeted)
            {
                TheLander.HasTarget=false;
                TheLander.HasCaptured=false;
                auto First=humanoid.Humanoids.begin();
                auto Last=humanoid.Humanoids.end();
                auto rawPtr=TheLander.Target;
      
                //Make use of the algorithm
                humanoid.Humanoids.erase(
                remove_if(
                    First,
                    Last,
                    [rawPtr](const std::shared_ptr<Humanoid>& sp) {
                    return sp.get() == rawPtr;
                    }
                    ),
                    Last
                    );

                BulletCollision=true;
            }

        }    
    
  return BulletCollision;

}

void LaserCollision:: EraseObjectFromLaser(vector<Laser>&BulletVector,MobileObject&bullet)
{


      auto First=BulletVector.begin();
      auto Last=BulletVector.end();
      
      
//  //Make use of the algorithm
//      humanoid.Humanoids.erase(
//         remove_if(
//             First,
//             Last,
//             [bullet](const std::shared_ptr<Laser>& sp) {
//                 return *sp ==&bullet;
//             }
//         ),
//         Last
//     );

}



