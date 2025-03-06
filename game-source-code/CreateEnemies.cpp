#include "CreateEnemies.h"

CreateEnemies::CreateEnemies()
{}
void CreateEnemies::EnemyCreation()
{   
    shared_ptr<Lander>TheLander=make_shared<Lander>();
    TheLander->CreateObject();
    lander.landers.push_back(TheLander);
    TheLander->ShootMissile();
}