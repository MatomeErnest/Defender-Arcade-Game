#ifndef SHIPFUELMONITOR_H
#define SHIPFUELMONITOR_H

#include "GameStrings.h"
#include "SpaceShip.h"

class ShipFuelMonitor
{
    public:
    void FillGas();
    void ConsumeGas();

    sf::Text* FuelLevel();
    int GasLevel();
    void restoreFuel();

    private:
    static int Gas;
    GameStrings gamestrings;
    SpaceShip spaceship;


};


#endif