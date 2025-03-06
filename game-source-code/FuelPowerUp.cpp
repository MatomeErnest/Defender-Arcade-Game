#include "FuelPowerUp.h"
FuelPowerUp::FuelPowerUp()
{}
void FuelPowerUp:: CreateGasPump()
{
    gaspump.setTexture(*(texture.GasPumpTexture()));
    gaspump.scale(sf::Vector2f(0.25f,0.25f));
    gaspump.setPosition(sf::Vector2f(800.f,780.f));
}
sf::Sprite FuelPowerUp:: gaspump;
bool FuelPowerUp:: GasPumpExists=false;