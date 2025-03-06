#include "MobileObject.h"

 MobileObject::MobileObject()
 {
  
 }

void MobileObject:: MoveLeft()
{
    thesprite.move(-SpriteSpeed_,0.f);
}

void MobileObject:: MoveRight()
{
    thesprite.move(SpriteSpeed_,0.f);

}
void MobileObject:: MoveUp()
{
    thesprite.move(0.f,-SpriteSpeed_);

}
void MobileObject:: MoveDown()
{
    thesprite.move(0.f,SpriteSpeed_);

}

sf::Sprite* MobileObject:: TheSprite()
{
    return &thesprite;
}

