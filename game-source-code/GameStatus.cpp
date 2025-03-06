#include "GameStatus.h"
void GameStatus::RestartGame()
{
    
    humanoid.ResetHumanoids();
    for(auto i=0;i<5;i++)
    {
        shared_ptr<Humanoid>TheHumanoid=make_shared<Humanoid>();
        TheHumanoid->CreateObject();
        humanoid.Humanoids.push_back(TheHumanoid);
    }

    shield.resetShields();

    (*spaceship.TheShip.begin())->ResetShipStatus();

    lasers.bulletsvector.clear();
    lander.landers.clear();
    lander.NumberofLanders=0;
    missile.Missiles.clear();
    gameplay=true;
    GameEnd=false;
    beginning=false;
    victory=false;
    loss=false;

    scores.UpdateHighestScore();
    scores.currentscore=0;
    spaceship.OutOfFuel=false;
    fuelmonitor.restoreFuel();   
}
void GameStatus:: Victory()
{
    gameplay=false;
    beginning=false;
    GameEnd=true;
    victory=true;
}
void GameStatus:: Loss()
{
    gameplay=false;
    beginning=false;
    GameEnd=true;
    loss=true;
}
bool GameStatus:: gameplay=false;
bool GameStatus:: beginning=true;
bool GameStatus:: GameEnd=false;
bool GameStatus:: victory=false;
bool GameStatus:: loss=false;