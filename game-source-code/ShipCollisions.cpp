#include "ShipCollisions.h"

void ShipCollisionDetections:: ShipCollisions()
{
    

    if(spaceship.OutOfFuel)
    {
    ShipScreenCollision(*(*spaceship.TheShip.begin()));//At the bottom while its falling
    }else
    {
      ShipFuelRelatedCollisions(*(*spaceship.TheShip.begin()),fuel.gaspump);///SHIPANDFuelPUmp 

      /////////SPACESHIP and humaniod
        for(auto Iter=humanoid.Humanoids.begin();Iter<humanoid.Humanoids.end();Iter++)
        {

            ShipHumanoidCollision(*(*spaceship.TheShip.begin()),(*(*Iter)));//polls for collisions
        }

        //////////////////////////for Spaceship and lander
        for(auto Iter=lander.landers.begin();Iter<lander.landers.end();Iter++)
        {

            ShipLanderCollision(*(*spaceship.TheShip.begin()),(*(*Iter)));//polls for collisions
        }
    }




    ///all collisions are managed
}

void ShipCollisionDetections:: ShipFuelRelatedCollisions(SpaceShip& Ship,sf::Sprite& ShipFuel)
{
    
   if(fuel.GasPumpExists)
    {
        if(ShipFuelPumpCollision(Ship,ShipFuel))
        {
            fuel.GasPumpExists=false;
            fuelmonitor.FillGas();
        }
        
    }
  

}

bool ShipCollisionDetections:: ShipFuelPumpCollision(SpaceShip&ship,sf::Sprite&fuelpump)
{
    auto Collided=false;

      sf::FloatRect  MainBoundingBox=fuelpump.getGlobalBounds();
      sf::FloatRect  collidingbox=ship.TheSprite()->getGlobalBounds();
      if(collidingbox.intersects(MainBoundingBox))
      {
        Collided=true;
      }
    
  return Collided;

}



void ShipCollisionDetections:: ShipScreenCollision(SpaceShip&TheShip)
{

    if(ScreenCollision(TheShip))
    {
        gamestatus.Loss();
    }

}

bool ShipCollisionDetections:: ScreenCollision(MobileObject& collidingObject)
{
    auto Collided=false;
  sf::Vector2f spritePosition = collidingObject.TheSprite()->getPosition();
  sf::Vector2u windowSize = sf::Vector2u(dimensions.WindowWidth(),dimensions.WindowHeight());
  sf::Vector2f spriteSize = sf::Vector2f(collidingObject.TheSprite()->getTexture()->getSize());

  if(spritePosition.y+spriteSize.y>=windowSize.y)
    {
        
        Collided=true;
        
    }
  return Collided;
}


void ShipCollisionDetections:: ShipHumanoidCollision(SpaceShip&Theship,Humanoid&Thehumanoid)
{
    if(Thehumanoid.freed)
    {
 
      if(ObjectToObjectCollision(Thehumanoid,Theship))
      {
          if (!Thehumanoid.FollowShip&&
          !Theship.IsSaving)
          {
            Theship.IsSaving=true;
            Thehumanoid.FollowShip=true;
           }
      }

    }
}

 void ShipCollisionDetections:: ShipLanderCollision(SpaceShip&Theship,Lander&Thelander)
 {

if(!Theship.isInvulnerable && ObjectToObjectCollision(Theship,Thelander))
  {
        auto First=lander.landers.begin();
        auto Last=lander.landers.end();

        lander.landers.erase(
          remove_if(
            First,
            Last,
            [Thelander](const std::shared_ptr<Lander>& sp) {
                return sp.get() ==&Thelander;
            }
        ),
        Last
     );

  gamestatus.Loss();
  scoresystem.UpdateHighestScore();
  }

 }