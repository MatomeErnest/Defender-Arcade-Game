#include "Missile.h"

Missile::Missile()
{

}
Missile::Missile(sf::Vector2f ShipPosition,sf::Vector2f LanderPosition):
ShipPosition_{ShipPosition},MissilePosition_{LanderPosition}

{
    
}

void Missile:: CreateObject()
{
    thesprite.setTexture(*(texture.getMissile()));
    thesprite.scale(sf::Vector2f(0.26f,0.26f));
    thesprite.setPosition(sf::Vector2f(MissilePosition_.x,MissilePosition_.y));
    direction=ShipPosition_- MissilePosition_;
    direction = direction / sqrt(direction.x * direction.x + direction.y * direction.y);
    SpriteSpeed_=MissileSpeed;

}





void Missile:: MoveObject()
{
    thesprite.move(direction*MissileSpeed);

}

vector<shared_ptr<Missile>> Missile::Missiles(0);