#ifndef DIMENSIONS_H
#define DIMENSIONS_H

#include <iostream>

class Dimensions
{
public:
//THESE FUNCTIONS SHOULD RETURN AN sf::vector2
    int WindowHeight() const;
    int WindowWidth() const;

    //SpaceShip Speed
    float ShipSpeed() const;
    
    //Bullet Speed

    float LaserSpeed() const;

    //Lander Speed
    float LanderSpeed() const;

    //Missile Speed
    float MissileSpeed() const;

private:
  const int windowheight=900;
   const int windowwidth=1600;
   const float shipSpeed=0.5f;
   const float laserspeed=0.1f;
   const float landerspeed=0.4f;
   const float missilespeed=0.6f;
  
};

#endif