#include "ShipFuelMonitor.h"

void ShipFuelMonitor:: FillGas()
{
    Gas+=50;
}
void ShipFuelMonitor:: ConsumeGas()
{
    Gas-=1;
    if(Gas<=0)
    {
       spaceship.OutOfFuel=true;
    }
}

sf::Text* ShipFuelMonitor:: FuelLevel()
{

    return gamestrings. SpaceShipFuel(Gas);
}

int ShipFuelMonitor:: GasLevel()
{
    return Gas;
}

void ShipFuelMonitor:: restoreFuel()
{
    Gas=100;
}

int ShipFuelMonitor:: Gas=100;