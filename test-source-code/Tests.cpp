#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "SpaceShip.h"
#include "Laser.h"
#include "Lander.h"
#include "GameCollisions.h"
#include "SpaceShip.h"
#include "Missile.h"
#include "GameStatus.h"
#include "ScoringSystem.h"
#include "MoveUncontrolled.h"
//////////////////////////////Basic test for Scoring  System//////////////////////////////
TEST_CASE("Game Score starts at 0")
{

    auto scores=ScoringSystem{};

    CHECK(scores.currentscore==0);

}
TEST_CASE("Game Score can be incremented")
{
    auto scores=ScoringSystem{};
    scores.IncrementScore(10);

    CHECK(scores.currentscore==10);
}

TEST_CASE("Highest game score is initially Zero")
{
    auto scores=ScoringSystem{};
    //scores.IncrementScore(10);
    
    CHECK(scores.highestscore==0);
}


// ////////////////////////////////////////////////Basic Tests For shield///////////////////////////////
TEST_CASE("Ship fuel level starts at 100")
{
    ShipFuelMonitor shipfuel;
    auto Fuel=shipfuel.GasLevel();
    CHECK(Fuel==100);
}

TEST_CASE("Ship fuel level can be decreased")
{
    ShipFuelMonitor shipfuel;
    shipfuel.ConsumeGas();
    
    auto Fuel=shipfuel.GasLevel();
    CHECK(Fuel==99);
}

TEST_CASE("Ship fuel level can be increased")
{
    ShipFuelMonitor shipfuel;
    auto CurrentFuelLevel=shipfuel.GasLevel();

    shipfuel.FillGas();
    auto UpdatedFuelLevel=shipfuel.GasLevel();
    CHECK(UpdatedFuelLevel==CurrentFuelLevel+50);
}

// /////////////////////////////////////////////////Basic Tests for Humanoid/////////////////////////////////


TEST_CASE("Humanoid Can Move up")
{
    Humanoid humanoid;
    humanoid.CreateObject();

    auto CurrentPosition=humanoid.TheSprite()->getPosition();
    humanoid.MoveUp();

    auto MovedPosition=humanoid.TheSprite()->getPosition();

    CurrentPosition.y-=2.f;
    
   CHECK(MovedPosition==CurrentPosition);
}

 TEST_CASE("Humanoid Can Move Down")
{
    Humanoid humanoid;
    humanoid.CreateObject();

    auto CurrentPosition=humanoid.TheSprite()->getPosition();
    humanoid.MoveDown();

    auto MovedPosition=humanoid.TheSprite()->getPosition();

    CurrentPosition.y+=2.f;
    
   CHECK(MovedPosition==CurrentPosition);
}

TEST_CASE("Humanoid OnlY Moves to the Right when saved by Player")
{
    Humanoid humanoid;
    humanoid.CreateObject();
    
   CHECK_THROWS_AS(humanoid.MoveRight(),HumanoidCannotMoveHozintally);
}

TEST_CASE("Humanoid OnlY Moves to the Left when saved by Player")
{
    Humanoid humanoid;
    humanoid.CreateObject();
    
   CHECK_THROWS_AS(humanoid.MoveLeft(),HumanoidCannotMoveHozintally);
}

// ///////////////////////////////Lander Basic Movement tests///////////////////////////////////////////////////
  TEST_CASE("Lander moves to the right")
 {
 
    Lander lander;
    lander.CreateObject();
    auto CurrentPosition=lander.TheSprite()->getPosition();
    lander.LanderDirection=Directions::RIGHT;
    lander.MoveObject();

    CurrentPosition.x+=2.f;
   CHECK(lander.TheSprite()->getPosition()==CurrentPosition);
    
 }

   TEST_CASE("Lander moves to the left")
 {

    Lander lander;
    lander.CreateObject();
    auto CurrentPosition=lander.TheSprite()->getPosition();
    lander.LanderDirection=Directions::LEFT;
    lander.MoveObject();
    CurrentPosition.x-=2.f;
    CHECK(lander.TheSprite()->getPosition()==CurrentPosition);
    
 }

 TEST_CASE("Lander moves Up")
 {

    Lander lander;
    lander.CreateObject();
    auto CurrentPosition=lander.TheSprite()->getPosition();
    lander.LanderDirection=Directions::UP;
    lander.MoveObject();
    CurrentPosition.y-=2.f;
    CHECK(lander.TheSprite()->getPosition()==CurrentPosition);
    
 }

  TEST_CASE("Lander moves Down")
 {

    Lander lander;
    lander.CreateObject();
    auto CurrentPosition=lander.TheSprite()->getPosition();
    lander.LanderDirection=Directions::DOWN;
    lander.MoveObject();
    CurrentPosition.y+=2.f;
    CHECK(lander.TheSprite()->getPosition()==CurrentPosition);

 }
//  ///////////////////////////////////////////////SpaceShip basic Movement test////////////////////////////////

 TEST_CASE("Start position of the ship is the middle of the window")
{
    SpaceShip ship;
    ship.CreateObject();
    auto initial_pos=sf::Vector2f(700.f,400.f);
    CHECK(ship.TheSprite()->getPosition()==initial_pos);
}

TEST_CASE("Ship moves right with the set speed")
{
    SpaceShip ship;
    ship.CreateObject();
    
    auto CurrentPosition=ship.TheSprite()->getPosition();

    ship.shipdirection_=Directions::RIGHT;
    ship.MoveObject();
    CurrentPosition.x+=65.f;
    CHECK(ship.TheSprite()->getPosition()==CurrentPosition);
}
TEST_CASE("Ship moves left with the set speed")
{
    SpaceShip ship;
    ship.CreateObject();
    
    auto CurrentPosition=ship.TheSprite()->getPosition();
    
    ship.shipglobaldirection=Directions::LEFT;
    ship.MoveObject();
    CurrentPosition.x-=65.f;
    CHECK(ship.TheSprite()->getPosition()==CurrentPosition);
}
TEST_CASE("Ship can move down")
{
    SpaceShip ship;
    ship.CreateObject();
    
    auto CurrentPosition=ship.TheSprite()->getPosition();
    
    ship.shipglobaldirection=Directions::DOWN;
    ship.MoveObject();
    CurrentPosition.y+=65.f;
    CHECK(ship.TheSprite()->getPosition()==CurrentPosition); 
}
TEST_CASE("Ship can move up")
{
    SpaceShip ship;
    ship.CreateObject();
    
    auto CurrentPosition=ship.TheSprite()->getPosition();
    ship.shipglobaldirection=Directions::UP;
    ship.MoveObject();
    CurrentPosition.y-=65.f;
    CHECK(ship.TheSprite()->getPosition()==CurrentPosition); 
}

// /////////////////////////////////////Missile basic Movement Tests/////////////////////////////////
TEST_CASE("Missile moves to the left")
 {
    auto missile=Missile(sf::Vector2f(50,300),sf::Vector2f(400,300));
    missile.CreateObject();
    auto CurrentPosition=missile.TheSprite()->getPosition();

    missile.MoveObject();
    CurrentPosition.x-=4.f;
   CHECK(missile.TheSprite()->getPosition()==CurrentPosition);
 }

TEST_CASE("Missile moves to the right")
 {
    auto missile=Missile(sf::Vector2f(400,300),sf::Vector2f(50,300));
    missile.CreateObject();
    auto CurrentPosition=missile.TheSprite()->getPosition();
    missile.MoveObject();
    CurrentPosition.x+=4.f;
   CHECK(missile.TheSprite()->getPosition()==CurrentPosition);
 }

TEST_CASE("Missile moves to the up")
 {
    auto missile=Missile(sf::Vector2f(400,50),sf::Vector2f(400,300));
    missile.CreateObject();
    auto CurrentPosition=missile.TheSprite()->getPosition();
    missile.MoveObject();
    CurrentPosition.y-=4.f;
   CHECK(missile.TheSprite()->getPosition()==CurrentPosition);
 }
 TEST_CASE("Missile moves down")
 {
    auto missile=Missile(sf::Vector2f(400,500),sf::Vector2f(400,300));
    missile.CreateObject();
    auto CurrentPosition=missile.TheSprite()->getPosition();
    missile.MoveObject();
    CurrentPosition.y+=4.f;
   CHECK(missile.TheSprite()->getPosition()==CurrentPosition);
 }

// /////////////////////////////////////////////////////Beginning of Collision Tests///////////////////////////////////////////

// /////////////////////////////////Lander Collision Tests///////////////////////////////////////////

  TEST_CASE("Lander Collision with Humanoid is detected")
 {
    Lander lander;
    lander.CreateObject();
    

    Humanoid humanoid;
    humanoid.CreateObject();

    lander.Target=&humanoid;
    lander.HasTarget=true;

    LanderCollision collisions;
    
    auto HumanoidPosition=humanoid.TheSprite()->getPosition();

    lander.TheSprite()->setPosition(HumanoidPosition);
  
    auto IsCollided=collisions.ObjectToObjectCollision(lander,humanoid);

   CHECK(IsCollided);
 }

  TEST_CASE("Lander Collision with screen is detected")
 {
    Lander lander;
    lander.CreateObject();
    
    LanderCollision collisions;
    
    auto newLanderPosition=sf::Vector2f(0.f,0.f);

    lander.TheSprite()->setPosition(newLanderPosition);
  
    auto IsCollided=collisions.ScreenCollision(lander);

    CHECK(IsCollided);
 }

 // //  /////////////////////////////////SpaceShip Collision Tests///////////////////////////////////////////

  TEST_CASE("Spaceship Collision with Lander is detected")
 {
    Lander lander;
    lander.CreateObject();
    

    SpaceShip ship;
    ship.CreateObject();


    ShipCollisionDetections collisions;
    
    auto LanderPosition=lander.TheSprite()->getPosition();

    ship.TheSprite()->setPosition(LanderPosition);
  
    auto IsCollided=collisions.ObjectToObjectCollision(lander,ship);

    CHECK(IsCollided);
 }

   TEST_CASE("SpaceShip Collision with Humanoid is detected")
 {
    SpaceShip spaceship;
    spaceship.CreateObject();
    

    Humanoid humanoid;
    humanoid.CreateObject();


    ShipCollisionDetections collisions;
    
    auto HumanoidPosition=humanoid.TheSprite()->getPosition();

    spaceship.TheSprite()->setPosition(HumanoidPosition);
  
    auto IsCollided=collisions.ObjectToObjectCollision(humanoid,spaceship);

    CHECK(IsCollided);
 }

  TEST_CASE("SpaceShip Collision with screen is detected")
 {
    SpaceShip spaceship;
    spaceship.CreateObject();
    
    ShipCollisionDetections collisions;
    
    auto newLanderPosition=sf::Vector2f(0.f,900.f);

    spaceship.TheSprite()->setPosition(newLanderPosition);
  
    auto IsCollided=collisions.ScreenCollision(spaceship);

    CHECK(IsCollided);
}

TEST_CASE("SpaceShip Collision with FuelPump is detected")
 {
    SpaceShip spaceship;
    spaceship.CreateObject();

    FuelPowerUp fuel;
    fuel.CreateGasPump();
    fuel.GasPumpExists=true;//Exists on the street
    
    ShipCollisionDetections collisions;
    
    auto fuelPowerUpPosition=fuel.gaspump.getPosition();

    spaceship.TheSprite()->setPosition(fuelPowerUpPosition);
  
    auto IsCollided=collisions.ShipFuelPumpCollision(spaceship,fuel.gaspump);

    CHECK(IsCollided);
}
/////////////////////////////////Missile Collision Tests///////////////////////////////////////////

   TEST_CASE("Missile Collision with Ship is detected")
 {
    SpaceShip spaceship;
    spaceship.CreateObject();
    
    Missile missile;
    missile.CreateObject();


    MissileCollision collisions;
    
    auto ShipPosition=spaceship.TheSprite()->getPosition();

    missile.TheSprite()->setPosition(ShipPosition);
  
    auto IsCollided=collisions.MissileShipCollision(missile,spaceship);

    CHECK(IsCollided);
 }

TEST_CASE("Missile Collision with screen is detected")
 {
    Missile missile;
    missile.CreateObject();
    
    MissileCollision collisions;
    
    auto newMissilePosition=sf::Vector2f(0.f,0.f);

    missile.TheSprite()->setPosition(newMissilePosition);
  
    auto IsCollided=collisions.MissileScreenCollision(missile);

    CHECK(IsCollided);
}

 /////////////////////////////////Laser Collision Tests///////////////////////////////////////////

   TEST_CASE("Bullet Collision with Missile is detected")
 {
    Laser laser;
    laser.CreateObject();
    
    Missile missile;
    missile.CreateObject();

    LaserCollision collisions;
    
    auto MissilePosition=missile.TheSprite()->getPosition();

    laser.TheSprite()->setPosition(MissilePosition);
  
    auto IsCollided=collisions.BulletMissileCollision(laser,missile);

    CHECK(IsCollided);
 }
 
   TEST_CASE("Bullet Collision with Lander is detected")
 {
    Laser laser;
    laser.CreateObject();
    
    Lander lander;
    lander.CreateObject();


    LaserCollision collisions;
    
    auto LanderPosition=lander.TheSprite()->getPosition();

    laser.TheSprite()->setPosition(LanderPosition);
  
    auto IsCollided=collisions.BulletLanderCollision(laser,lander);

    CHECK(IsCollided);
 }

    TEST_CASE("Bullet Collision with Humanoid is detected")
 {
    Laser laser;
    laser.CreateObject();
    
    Humanoid humanoid;
    humanoid.CreateObject();


    LaserCollision collisions;
    
    auto HumanoidPosition=humanoid.TheSprite()->getPosition();

    laser.TheSprite()->setPosition(HumanoidPosition);
  
    auto IsCollided=collisions.ObjectToObjectCollision(laser,humanoid);

    CHECK(IsCollided);
 }

    TEST_CASE("Laser Collision with screen is detected")
 {
    Laser laser;
    laser.CreateObject();
    
    LaserCollision collisions;
    
    auto newLaserPosition=sf::Vector2f(0.f,0.f);

    laser.TheSprite()->setPosition(newLaserPosition);
    auto IsCollided=collisions.BulletScreenCollision(laser);

    CHECK(IsCollided);
}



/////////////////////////////////Test For Logic Begin//////////////////////////////////////

///////////////////////////////////Logic Tests for the lander/////////////////////////////////

  TEST_CASE("Lander move up if collided with Humanoid")
 {
    Lander lander;
    lander.CreateObject();
    lander.HasTarget=true;

    Humanoid humanoid;
    humanoid.CreateObject();
    humanoid.Targeted=true;

    lander.Target=&humanoid;//records this humanoid as its target
    LanderCollision collisions;
    MoveUncontrolled moveuncontrolled;
    
    auto HumanoidPosition=humanoid.TheSprite()->getPosition();

    lander.TheSprite()->setPosition(HumanoidPosition);

    collisions.LanderHumanoidCollision(lander,*(lander.Target));

    moveuncontrolled.MoveLanders(lander);
    //check that lander has changed direction to Up
    CHECK(lander.LanderDirection==Directions::UP);
 }

   TEST_CASE("Lander Changes direction if collided with the screen")
 {
    Lander lander;
    lander.CreateObject();

    auto InitialDirection=lander.LanderDirection;
    
    LanderCollision collisions;
    MoveUncontrolled moveuncontrolled;
    
   auto newLanderPosition=sf::Vector2f(0.f,0.f);

    lander.TheSprite()->setPosition(newLanderPosition);

    collisions.LanderScreenCollision(lander);

    auto FinalDirection=lander.LanderDirection;

    CHECK_FALSE(InitialDirection==FinalDirection);
 }
// //////////////////////////////////////////Logic Tests for Ship///////////////////////////////

TEST_CASE("Game is over when spaceship collides with Lander")
 {
    Lander lander;
    lander.CreateObject();
    

    SpaceShip spaceship;
    spaceship.CreateObject();
    
    GameStatus gamestatus;

    
    ShipCollisionDetections collisions;
    MoveUncontrolled moveuncontrolled;
    
    auto LanderPosition=lander.TheSprite()->getPosition();

    spaceship.TheSprite()->setPosition(LanderPosition);

    collisions.ShipLanderCollision(spaceship,lander);

    
    CHECK(gamestatus.GameEnd);
 }

 TEST_CASE("Ship shoots a missile")
 {
    Laser laser;

    SpaceShip spaceship;
    spaceship.CreateObject();
    spaceship.Shoot();

    CHECK(laser.bulletsvector.size()==1);
 }

 TEST_CASE("Fuel level increases if spaceship runs over the FuelPowerUp Object")
 {

    SpaceShip spaceship;
    spaceship.CreateObject();
    
    ShipFuelMonitor fuelmonitor;
    FuelPowerUp fuelpowerup;
    auto InitialFuelLevel=fuelmonitor.GasLevel();
    fuelpowerup.CreateGasPump();

    ShipCollisionDetections collisions;
    
    auto fuelTankPosition=fuelpowerup.gaspump.getPosition();

    spaceship.TheSprite()->setPosition(fuelTankPosition);//initiate a collision

    collisions.ShipFuelRelatedCollisions(spaceship,fuelpowerup.gaspump);

    auto CurrentFuelLevel=fuelmonitor.GasLevel();

    CHECK(CurrentFuelLevel>InitialFuelLevel);
 }

 TEST_CASE("The spaceship goes DOWN when fuel runs out")
 {

    SpaceShip spaceship;
    spaceship.CreateObject();

    ShipFuelMonitor fuelmonitor;
    
    while(fuelmonitor.GasLevel()>0)
    {
        fuelmonitor.ConsumeGas();
    }


    spaceship.MoveObject();

    CHECK(spaceship.shipglobaldirection==Directions::DOWN);
 }

 TEST_CASE("Ship doesnt move further if collided with screen with fuel")
 {

    SpaceShip spaceship;
    spaceship.CreateObject();
    
    auto newShipPosition=sf::Vector2f(1600.f,0.f);

    spaceship.TheSprite()->setPosition(newShipPosition);
    auto InitialPosition=spaceship.TheSprite()->getPosition();

    
    spaceship.MoveRight();
    
    auto FinalPosition=spaceship.TheSprite()->getPosition();

    CHECK(FinalPosition==InitialPosition);
 }

 TEST_CASE("Ship doesn`t get destroyed by missile while shielded")
 {
    GameStatus gamestatus;

    SpaceShip spaceship;
    spaceship.CreateObject();
    
    Shields shield;
    shield.CreateShields();

    MissileCollision collisions;
    
    Missile missile;
    missile.CreateObject();
    auto ShipPosition=spaceship.TheSprite()->getPosition();
    
    shield.activateShields(spaceship);
    
    missile.TheSprite()->setPosition(ShipPosition);
    auto IsCollided=collisions.MissileShipCollision(missile,spaceship);

    CHECK(!IsCollided);
 }

