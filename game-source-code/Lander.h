#ifndef LANDER_H
#define LANDER_H

#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
#include <sstream>
#include <random>
#include <chrono>
#include <iostream>
#include "Missile.h"
#include "SpaceShip.h"
#include "Humanoid.h"
#include <memory>



using namespace std;

class Lander:public MobileObject
{
public:
  Lander(); 
  virtual void CreateObject() override;
  virtual void MoveObject() override;
  void ChangeLanderDirection();
  void ShootMissile();
  void AttackHumanoid();
   
  static vector<shared_ptr<Lander>> landers;
  static float NumberofLanders;
  bool HasTarget=false;
  bool HasCaptured=false;
  bool IsLanderComparable=false;

  Directions LanderDirection;


  Humanoid*Target=nullptr;
 
private:
  float LanderSpeed=2.f;
  Missile missile;
  SpaceShip spaceship;
  sf::Vector2f direction;
  Humanoid humanoid;
  
};

#endif