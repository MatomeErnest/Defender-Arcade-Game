#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "GameEvents.h"
#include "DrawGameObjects.h"
#include "Window.h"
#include "UnControlledObjectsManagement.h"
#include <iostream>

using namespace std;
class GameLoop
{
public:
    GameLoop();
    void PlayGame();

private:
GameEvents gameevents;
Window window;
DrawGameObjects drawobjects;
MoveUncontrolled moveuncontrolled;
UnControlledObjects uncontrolled;
GameStatus status;
};

#endif