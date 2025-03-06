#include "Humanoid.h"

Humanoid:: Humanoid()
{

}


void Humanoid:: CreateObject()
{
    HumanoidInitialPosition=HumanoidPosition;

    SpriteSpeed_=HumanoidSpeed;
    thesprite.setTexture(*(texture.getHumanoidTexture()));
    thesprite.scale(sf::Vector2f(0.25f,0.25f));

    thesprite.setPosition(HumanoidPosition);
    HumanoidPosition.x+=368;

}
void Humanoid:: MoveObject()
{
    if(freed)
    {
         //MoveDown();
         thesprite.move(0,2.f);
    }else if (!freed)
    {
       
         thesprite.move(0,-2.f);
    }

}
void Humanoid:: MoveLeft()
{
    throw HumanoidCannotMoveHozintally{};
}
void Humanoid:: MoveRight()
{
    throw HumanoidCannotMoveHozintally{};
}

 void Humanoid:: ResetHumanoidStatus()
 {
    thesprite.setPosition(HumanoidInitialPosition);
    FollowShip=false;
    Targeted=false;
    PickedByLander=false;
    freed=false;
    

 }
void Humanoid:: followShip()
{
    humanoidDirection=(*(spaceship.TheShip.begin()))->TheSprite()->getPosition()-(thesprite.getPosition());
    
    //this->direction=(Target->TheSprite().getPosition())-(thesprite.getPosition());
    humanoidDirection=humanoidDirection/sqrt(humanoidDirection.x*humanoidDirection.x+humanoidDirection.y*humanoidDirection.y);

    thesprite.move(humanoidDirection*ShipSpeed);
}

void Humanoid:: ResetHumanoids()
{
    HumanoidPosition=sf::Vector2f(20.f,832.f);
    Humanoids.clear();

}


vector<shared_ptr<Humanoid>> Humanoid:: Humanoids(0);
sf::Vector2f Humanoid:: HumanoidPosition=sf::Vector2f(20.f,832.f);
