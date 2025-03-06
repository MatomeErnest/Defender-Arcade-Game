#ifndef UNCONTROLLEDOBJECTS_H
#define UNCONTROLLEDOBJECTS_H


#include "CreateEnemies.h"
#include "MoveUnControlled.h"
#include "FuelPowerUp.h"
#include "ShipFuelMonitor.h"
#include  "Shields.h"
#include "SpaceShip.h"
#include "Humanoid.h"
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

class UnControlledObjects
{
    public:
        UnControlledObjects();
        void UncontrolledObjectsManagement();
    private:
        FuelPowerUp fuel;

        CreateEnemies Enemy1;
        MoveUncontrolled moveuncontrolled;
        static int numberofenemies;
        static sf::Clock clock;
        sf::Time T=sf::seconds(2.0f);
        float LanderDelay;

        static sf::Clock clock1;
        sf::Time T1=sf::seconds(1.5f);
        float ShootingDelay;

        static sf::Clock clock2;
        sf::Time T2=sf::seconds(5.0f);
        float GasPumpDelay;

        static sf::Clock clock3;
        sf::Time T3=sf::seconds(0.1f);
        float FuelDecayDelay;
         
        static int shifter;
        SpaceShip ship;
        Lander lander;
        sf::Vector2f Position;
        bool Finish;

        ShipFuelMonitor fuelmonitor;
        Humanoid humanoid;
        static int Advancer;

        static sf::Clock clock4;
        sf::Time T4=sf::seconds(5.0f);
        float shieldsDelay;

        SpaceShip spaceship;
        Shields shields;
         
};

#endif