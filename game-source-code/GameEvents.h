#ifndef GAMEEVENTS_H
#define GAMEEVENTS_H

#include <SFML/Graphics.hpp>
#include "SpaceShip.h"
#include "Stars.h"
#include "GameStrings.h"
#include "GameStatus.h"
#include "ScoringSystem.h"
#include "Shields.h"

#include <memory>


class GameEvents
{
    public:
    GameEvents();
    void PollEvents(std::shared_ptr<sf::RenderWindow>thewindow);


    private:
    sf::Event ev;
    sf::Event event1;
    SpaceShip Ship;
    Stars stars;
    GameStrings gamestring;
    GameStatus gamestatus;
    ScoringSystem scores;
    Shields shields;
    bool RightKeyHeldDown=false;
    bool LeftKeyHeldDown=false;
   
    
    
   
};

#endif