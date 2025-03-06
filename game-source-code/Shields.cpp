#include "Shields.h"

Shields::Shields()
{}
 void Shields::CreateShields()
 {
    // Initialize the shield circles and add them to the vector
    for (int i = 0; i < NumShields; ++i) 
    {
        sf::CircleShape circle(radius);
        circle.setFillColor(sf::Color::Green); // Adjust color as needed
        // Position all circles at the top of the screen
        circle.setPosition(50 + i * (2 * radius + 10), 75);
        activeShields.push_back(circle);
    }
 }
 void Shields:: removelastshield()
 {
    if (!activeShields.empty()) 
    {
        activeShields.erase(activeShields.begin());
    }
 }
 void Shields::activateShields(SpaceShip&TheShip)
 {    
     //(*Ship.TheShip.begin())->setShipInvulnerable();
    if (getNumShields() > 0) 
    {
        isShieldActive = true;
        // Change the color of the currently active shield to red when activated
        (activeShields.begin())->setFillColor(sf::Color::Red);  
        TheShip.setShipInvulnerable();    
        clock4.restart();
    }
    if (getNumShields() < 0)
        {
            // No more shields left, disable further activation
            isShieldActive = false;
        }
    }
  void Shields::resetShields()
  {
    //Reset the number of shields to the maximum
    activeShields.clear();

    // Reset other relevant state
    isShieldActive = false;  // Ensure shields are not active
    NumShields = maxShields; // Reset the number of available shields
    clock4.restart();
    CreateShields();
  }
 
int Shields::getNumShields() const
  {
    return NumShields;
  }
  float Shields::getshieldsDelay()
  {
    return shieldsDelay;
  }
// Initialize the static vectors outside the class definition
bool Shields::isShieldActive=false;
sf::Clock Shields::clock4=sf::Clock{}; //Initialize the static member
std::vector<sf::CircleShape> Shields::activeShields;

