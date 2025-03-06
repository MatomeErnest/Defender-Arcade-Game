#ifndef SHIELDS_H
#define SHIELDS_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "SpaceShip.h"

class Shields
{
    public:
    Shields();
    void CreateShields();
    static bool isShieldActive;  // track whether the shield is currently active or not
    void activateShields(SpaceShip&TheShip);
    int getNumShields() const;
    void removelastshield();
    void resetShields();
    float getshieldsDelay();
    // Vector to store the shield circles
    static std::vector<sf::CircleShape> activeShields; // Use an vector to represent three circles
    static sf::Clock clock4;

    private: 
    float shieldsDelay=5.0f;
     sf::Time T4=sf::seconds(5.0f); // Adjust the duration as needed
     int NumShields=3;
     int maxShields=3;
     float radius=15.f; // The radius of the shield circles  
    
};
#endif