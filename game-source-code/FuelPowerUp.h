#ifndef FUELPOWERUP_H
#define FUELPOWERUP_H
#include "Textures.h"

class FuelPowerUp
{
    public:
        FuelPowerUp();
        void CreateGasPump();
        static sf::Sprite gaspump;
        static bool GasPumpExists;
    private:
    Textures texture;
};
#endif