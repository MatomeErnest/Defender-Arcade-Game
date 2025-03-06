#include "MoveUncontrolled.h"

MoveUncontrolled:: MoveUncontrolled()
{
  
  ShipDelay=T1.asSeconds();
  shipclock.restart();
  AttackingDelay=T.asSeconds();
  clock.restart();
}

void MoveUncontrolled:: MoveObjects()
{
if(!spaceship.OutOfFuel)
{
  MovemAmmunition();
  MoveEnemies();

}


if(spaceship.OutOfFuel)
{
  //auto Ship=converttobase(spaceship.TheShip);
  
  //(*spaceship.TheShip.begin())->shipglobaldirection=Directions::DOWN;
  (*spaceship.TheShip.begin())->MoveObject();
  //cout <<"Tried to move ship"<<endl;
  //MoveMobileObjects(*(*spaceship.TheShip.begin()));
}


collisions.CheckCollisions();

 
}

void MoveUncontrolled:: MoveBullets(Laser&TheLaser)
{

  MoveMobileObjects(TheLaser);
    
}


void MoveUncontrolled:: MoveLanders(Lander&TheLander)
{
 
    if((TheLander.HasTarget) &&!(TheLander.HasCaptured))
    {
      //cout <<"Attacked"<<endl;
      
      TheLander.AttackHumanoid();
      
    }else if(!(TheLander.HasTarget) &&!(TheLander.HasCaptured))
    {
      
      MoveMobileObjects(TheLander);
    }else if((TheLander.HasTarget) &&(TheLander.HasCaptured))
    {
      TheLander.LanderDirection=Directions::UP;
      MoveMobileObjects(TheLander);
    }  
  
}

void MoveUncontrolled:: MoveHumanoids(Humanoid&TheHumanoid)
{
  
    if(TheHumanoid.PickedByLander&&TheHumanoid.Targeted&&!TheHumanoid.freed)
    {
      
      TheHumanoid.MoveUp();
    }else if(!TheHumanoid.PickedByLander&&TheHumanoid.Targeted&&TheHumanoid.freed)
    {
      if(TheHumanoid.FollowShip&&spaceship.ShipMoved)
      {
        spaceship.ShipMoved=false;
        TheHumanoid.followShip();

      }else if(!TheHumanoid.FollowShip)
      {
        TheHumanoid.MoveDown();
      }
      
    }
  
}


void MoveUncontrolled::MoveMissiles(Missile&TheMissile)
{

    MoveMobileObjects(TheMissile);
  
}

void MoveUncontrolled:: MovemAmmunition()
{
  /////////////////////////////////Move bullets///////////////////////////////
    for(auto Iter=laser.bulletsvector.begin();Iter<laser.bulletsvector.end();Iter++)
    {
      MoveBullets(*(*Iter));
    }
  ////////////////////////////////Move Missile////////////////////////////////
    for(auto Iter=missiles.Missiles.begin();Iter<missiles.Missiles.end();Iter++)
    {

      MoveMissiles((*(*Iter)));

    }
  



}
void MoveUncontrolled:: MoveEnemies()
{
   //////////////////////////////Move Landers///////////////////////////////////////
    for(auto Iter=lander.landers.begin();Iter<lander.landers.end();Iter++)
    {
      MoveLanders(*(*Iter));
    }

    //////////////////////////////Move Humanoids///////////////////////////////////////
    for(auto Iter=humanoid.Humanoids.begin();Iter<humanoid.Humanoids.end();Iter++)
    {
      MoveHumanoids(*(*Iter));

    }
}


void MoveUncontrolled:: MoveMobileObjects(MobileObject& mobileobjects)
{
  mobileobjects.MoveObject();
}


sf::Clock MoveUncontrolled:: clock=sf::Clock{};
sf::Clock MoveUncontrolled:: shipclock=sf::Clock{};