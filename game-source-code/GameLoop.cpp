#include "GameLoop.h"
GameLoop::GameLoop()
{  
   srand(time(0)); 
}
void GameLoop:: PlayGame()
{
    while(window.Screen()->isOpen())
    {
        gameevents.PollEvents(window.Screen());
        if(status.gameplay)
        {
            uncontrolled.UncontrolledObjectsManagement();
        }
        window.Screen()->clear();
        drawobjects.DrawObjects(window.Screen());
        window.Screen()->display();
    }
}