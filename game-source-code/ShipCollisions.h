#ifndef SHIPCOLLISIONS
#define SHIPCOLLISIONS
#include "SpaceShip.h"
#include "FuelPowerUp.h"
#include "ShipFuelMonitor.h"
#include "Lander.h"
#include "Humanoid.h"
#include "ScoringSystem.h"
#include "GameStatus.h"

#include "CollisionsBase.h"

class ShipCollisionDetections:public CollisionsBase
{
    public:
        void ShipCollisions();
        void ShipFuelRelatedCollisions(SpaceShip& Ship,sf::Sprite& ShipFuel);
        void ShipLanderCollision(SpaceShip&TheShip,Lander&lander);
        void ShipScreenCollision(SpaceShip&TheShip);
        virtual bool ScreenCollision(MobileObject& colliding) override;
        bool ShipFuelPumpCollision(SpaceShip&ship,sf::Sprite&fuel);
        void ShipHumanoidCollision(SpaceShip&Theship,Humanoid&humanoid);
    
    private:
        ScoringSystem scoresystem;
        SpaceShip spaceship;
        Humanoid humanoid;
        FuelPowerUp fuel;
        ShipFuelMonitor fuelmonitor;
        GameStatus gamestatus;
        Lander lander;


};



#endif