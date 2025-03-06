#include "CollisionsBase.h"

bool CollisionsBase:: ObjectToObjectCollision(MobileObject& CollidedObject,MobileObject& CollidingObject)
{
    auto Collision=false;
    sf::FloatRect  CollidedBoundingBox=(CollidedObject).TheSprite()->getGlobalBounds();

    sf::FloatRect  CollidingBoundingBox=CollidingObject.TheSprite()->getGlobalBounds();
    if(CollidingBoundingBox.intersects(CollidedBoundingBox))
    {
        Collision=true;
    }

  return Collision;
}

bool CollisionsBase:: ScreenCollision(MobileObject& mobileobject)
{

    auto Collision=false;

  sf::Vector2f spritePosition = mobileobject.TheSprite()->getPosition();
  sf::Vector2u windowSize = sf::Vector2u(dimensions.WindowWidth(),dimensions.WindowHeight());
  sf::Vector2f spriteSize = sf::Vector2f((mobileobject).TheSprite()->getTexture()->getSize());

  //sf::FloatRect  boundingbox=(mobileobject).TheSprite().getGlobalBounds();



        if(spritePosition.y+spriteSize.y>windowSize.y)
        {
            Collision=true;
            
        }else if(spritePosition.y<110)
        {
          
          Collision=true;
        }
        if(spritePosition.x+spriteSize.x>windowSize.x)
        {
            
            Collision=true;
        }else if(spritePosition.x<0)
        {
          
          Collision=true;
        }
        

return Collision;
}