#ifndef CREATEENEMIES_H
#define CREATEENEMIES_H

#include <iostream>
#include "GameStatus.h"
#include "Lander.h"
#include <memory>

using namespace std;

class CreateEnemies
{
    public:
        CreateEnemies();
        void EnemyCreation();
    private:
        Lander lander;
        GameStatus gamestatus;
};

#endif