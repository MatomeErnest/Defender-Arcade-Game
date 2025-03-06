#ifndef GAMESTATUS_H
#define GAMESTATUS_H

#include "SpaceShip.h"
#include "Lander.h"
#include "ScoringSystem.h"
#include "ShipFuelMonitor.h"
#include "Humanoid.h"
#include "Shields.h"

class GameStatus
{
    public:
        void RestartGame();
        //void CheckGameOver();
        void Victory();
        void Loss();
        static bool gameplay;
        static bool beginning;
        static bool GameEnd;
        static bool victory;
        static bool loss;
    private:
        SpaceShip spaceship;
        Laser lasers;
        Lander lander;
        Missile missile;
        ScoringSystem scores;
        ShipFuelMonitor fuelmonitor;  
        Humanoid humanoid;
        Shields shield;
};
#endif