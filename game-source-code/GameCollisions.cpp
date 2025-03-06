#include "GameCollisions.h"


void GameCollisions::CheckCollisions()
{


  shipcollision.ShipCollisions();
  landercollision.LanderCollisions();
  missilecollision.MissileCollisions();
  lasercollision.LaserCollisions();
  humanoidcollision.HumanoidCollisions();

}












