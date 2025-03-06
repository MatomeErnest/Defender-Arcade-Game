#include "SpaceShip.h"

SpaceShip::SpaceShip()
{

}

void SpaceShip:: CreateObject()
{
    SpriteSpeed_=ShipSpeed;
    thesprite.setColor(sf::Color(128,0,0));
    thesprite.setTexture(*(texture.getSpaceShip()));
    thesprite.scale(sf::Vector2f(0.5f,0.5f));
    thesprite.setPosition(sf::Vector2f(700.f,400.f));
   
}

void SpaceShip::TurnLeft()
{
        if (!isSpaceShipTurnedLeft) 
   {
           isSpaceShipTurnedLeft=true;  //Set the facing direction to left
           //(*TheSprites.begin()).setScale(-std::abs((*TheSprites.begin()).getScale().x), (*TheSprites.begin()).getScale().y);
           thesprite.setScale(-std::abs(thesprite.getScale().x), thesprite.getScale().y);
           shipdirection_=Directions::LEFT;
   }   
}

void SpaceShip::TurnRight()
{
    if (isSpaceShipTurnedLeft) 
    {
        isSpaceShipTurnedLeft=false; // Set the facing direction to right
        thesprite.setScale(std::abs(thesprite.getScale().x), thesprite.getScale().y);
        shipdirection_=Directions::RIGHT;
        
     }
 
}
void SpaceShip:: Shoot()
{
   shared_ptr<Laser>bullet=make_shared<Laser>(thesprite.getPosition(),shipdirection_);
   bullet->CreateObject();
   laser.bulletsvector.push_back(bullet);   
}


Directions SpaceShip:: shipdirection()
{

   return shipdirection_;
}

void SpaceShip::MoveRight()
{
// auto windowwidth=static_cast<float>()
if(thesprite.getPosition().x<(dimensions.WindowWidth()-thesprite.getTexture()->getSize().x))
{
    thesprite.move(ShipSpeed,0.f);
}


}
 void SpaceShip::MoveLeft()
{
    if(thesprite.getPosition().x>70 )
    {
    thesprite.move(-ShipSpeed,0.f);
    }
    
}

void SpaceShip::MoveUp()
{
    if(thesprite.getPosition().y>180)
    {
    thesprite.move(0.f,-ShipSpeed);
    }
}

void SpaceShip::MoveDown()
{
    if(thesprite.getPosition().y<(dimensions.WindowHeight()-thesprite.getTexture()->getSize().y))
    {
    thesprite.move(0.f,ShipSpeed);
    }
    
}


void SpaceShip:: MoveObject()
{
    
    if(OutOfFuel)
    {
        ShipSpeed=FallingShipSpeed;
        shipglobaldirection=Directions::DOWN;
    }
    switch(shipglobaldirection)
    {

        case Directions::RIGHT:
            MoveRight();
            break;

        case Directions::LEFT:
            MoveLeft();
            break;
            
        case Directions::UP:
            MoveUp();
            break;

        case Directions::DOWN:
            MoveDown();
            break;

        default:
            break;

    }
}

void  SpaceShip::setShipInvulnerable()
{
    
   
        isInvulnerable = true;
        // Add logic to change ship color or provide visual indication of invulnerability
        thesprite.setColor(sf::Color::Cyan);
    
  }
void SpaceShip::OriginalColor() 
{

	// Before making any color changes, manually record the original color
	sf::Color originalColor = sf::Color(128, 0, 0); 
	thesprite.setColor(originalColor);
}

void SpaceShip:: ResetShipStatus()
{
    thesprite.setPosition(sf::Vector2f(700.f,400.f));
    ShipSpeed=65.f;
    OutOfFuel=false;
}


Directions SpaceShip:: shipdirection_=Directions::RIGHT;
Directions SpaceShip::shipglobaldirection=Directions::RIGHT;
vector<shared_ptr<SpaceShip>> SpaceShip:: TheShip(0);

bool SpaceShip:: ShipMovedRight=false;
bool SpaceShip:: ShipMovedLeft=false;
bool SpaceShip:: OutOfFuel=false;
bool SpaceShip:: IsSaving=false;
bool SpaceShip:: ShipMoved=false;
bool SpaceShip::isInvulnerable=false;