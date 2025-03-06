#ifndef DRAWGAMEOBJECTS_H
#define DRAWGAMEOBJECTS_H

//#include "SpaceShip.h"
#include "Stars.h"
#include "GameStrings.h"
#include "SplashBackground.h"
#include "GameStatus.h"
#include "Laser.h"
#include "Lander.h"
#include "Shields.h"
#include "ScoringSystem.h"
#include "FuelPowerUp.h"
#include "ShipFuelMonitor.h"

using namespace std;

using WindowPtr=shared_ptr<sf::RenderWindow>;
using MobileObjectsVector=vector<shared_ptr<MobileObject>>;
class DrawGameObjects
{
    public:
    void DrawObjects(std::shared_ptr<sf::RenderWindow>thewindow);
    void drawship(std::shared_ptr<sf::RenderWindow>thewindow);
    void DrawLaser(std::shared_ptr<sf::RenderWindow>thewindow);
    void DrawLander(std::shared_ptr<sf::RenderWindow>thewindow);
    void DrawMissile(std::shared_ptr<sf::RenderWindow>thewindow);
    void DrawHumanoids(std::shared_ptr<sf::RenderWindow>thewindow);
    void drawstars(std::shared_ptr<sf::RenderWindow>thewindow);
    void DrawSplashScreen(std::shared_ptr<sf::RenderWindow>thewindow);
    void DrawEndGameScreen(std::shared_ptr<sf::RenderWindow>thewindow);
    void DrawMobileObjects(MobileObject& mobileobject,WindowPtr);

    void DrawScores(std::shared_ptr<sf::RenderWindow>thewindow);
    void DrawFuelPump(std::shared_ptr<sf::RenderWindow>thewindow);
    void DrawFuelLevels(std::shared_ptr<sf::RenderWindow>thewindow);
    void DrawShields(std::shared_ptr<sf::RenderWindow>thewindow);
    void DrawDividingLines(std::shared_ptr<sf::RenderWindow>thewindow);

 


    private:
    SpaceShip spaceship;
    Laser laser;
    Stars stars;
    Lander lander;
    Humanoid humanoid;
    Missile missile;
    GameStrings strings;
    SplashBackground splashbackground;
    GameStatus gamestatus;

    ScoringSystem scoresystem;
    FuelPowerUp fuel;
    ShipFuelMonitor fuelmonitor;
    Shields shield;

    
};

#endif