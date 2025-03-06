#include "Laser.h"
#include "Directions.h"

Laser::Laser()
{}

 Laser::Laser(sf::Vector2f ShipPosition,Directions shipdirection):
 ShipPosition_{ShipPosition},shipdirection_{shipdirection}
 {}

void Laser::CreateObject()
{
    thesprite.setTexture(*(texture.getBullet()));
    thesprite.scale(sf::Vector2f(0.6f,0.6f));
    thesprite.setPosition(ShipPosition_.x+10.f,ShipPosition_.y+15.f);
    BulletDirection =shipdirection_;
    SpriteSpeed_=BulletSpeed; 
}
void Laser:: MoveObject()
{  

     switch(BulletDirection)
        {

            case Directions::LEFT:
            MoveLeft();
            break;

            case Directions::RIGHT:
            MoveRight();
            break;

            default:
            break;
        }    

}
void Laser:: MoveUp()
{
    throw BulletDoesntMoveVertical{};
   
}

void Laser:: MoveDown()
{
    throw BulletDoesntMoveVertical{};
    
}
vector <shared_ptr<Laser>> Laser:: bulletsvector(0);
