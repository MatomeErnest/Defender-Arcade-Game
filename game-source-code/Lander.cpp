#include "Lander.h"

Lander::Lander()
{

}

void Lander:: CreateObject()
{
    sf::Vector2f direction;
    //sf::Sprite lander;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(-1.0f, 1.0f); // Random numbers between -1 and 1

    direction=sf::Vector2f(dis(gen), dis(gen)); 
  

    SpriteSpeed_=LanderSpeed;
    thesprite.setTexture(*(texture.getLander()));
    thesprite.scale(sf::Vector2f(0.25f,0.25f));

    mt19937 diceGenerator(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> diceDistribution(100,1400);
	auto RandomX= diceDistribution(diceGenerator);

	uniform_int_distribution<int> DiceDistribution(100,750);
	auto RandomY =DiceDistribution(diceGenerator);
    
     thesprite.setPosition(sf::Vector2f(RandomX,RandomY));

	uniform_int_distribution<int> Dicedistribution(0,7);
	auto randomdirec =Dicedistribution(diceGenerator);

    LanderDirection=static_cast<Directions>(randomdirec);


///////////////////////////////////////////////////////////////////////////////////
    NumberofLanders+=1;
  
}

void Lander:: ShootMissile()
{
    shared_ptr<Missile>TheMissile=make_shared<Missile>(spaceship.TheShip.front()->TheSprite()->getPosition(),thesprite.getPosition());
    TheMissile->CreateObject();
    missile.Missiles.push_back(TheMissile);
}




void Lander:: ChangeLanderDirection()
{
    mt19937 diceGenerator(chrono::system_clock::now().time_since_epoch().count());
    if(thesprite.getPosition().x<0)
    {
        uniform_int_distribution<int> Dicedistribution(4,7);
	    auto randomdirec =Dicedistribution(diceGenerator);
        LanderDirection=static_cast<Directions>(randomdirec); 
    }else if(thesprite.getPosition().x+thesprite.getTexture()->getSize().x>1600)
    {
        uniform_int_distribution<int> Dicedistribution(0,3);
	    auto randomdirec =Dicedistribution(diceGenerator);
        LanderDirection=static_cast<Directions>(randomdirec);     
    }else if(thesprite.getPosition().y<110)
    {
        uniform_int_distribution<int> Dicedistribution(3,7);
	    auto randomdirec =Dicedistribution(diceGenerator);
        LanderDirection=static_cast<Directions>(randomdirec);

    }else if(thesprite.getPosition().y+thesprite.getTexture()->getSize().y>800)
    {
        uniform_int_distribution<int> Dicedistribution(0,4);
	    auto randomdirec =Dicedistribution(diceGenerator);
        LanderDirection=static_cast<Directions>(randomdirec);  
    }

     
}

void Lander:: AttackHumanoid()
{
    direction=(Target)->TheSprite()->getPosition()-(thesprite.getPosition());
    //this->direction=(Target->TheSprite().getPosition())-(thesprite.getPosition());
    direction=direction/sqrt(direction.x*direction.x+direction.y*direction.y);

    thesprite.move(direction*LanderSpeed);
}
void Lander:: MoveObject()
{
    

            switch(LanderDirection)
    {
        case Directions::D_RIGHTUP:
        
            MoveRight();
            MoveUp();
            break;
        case Directions::D_RIGHTDOWN:
            MoveRight();
            MoveDown();           
            
            break;       
        case Directions::RIGHT:
            MoveRight();
            break;
        case Directions::UP:
            MoveUp();
            break;     
        case Directions::DOWN:
            MoveDown();
            break;
        case Directions::D_LEFTUP:
            MoveLeft();
            MoveUp();
            break;
        case Directions::D_LEFTDOWN:
            MoveLeft();
            MoveDown();
            break;
        case Directions::LEFT:
            MoveLeft();
            break;
        default:
            break;
}
}

vector<shared_ptr<Lander>> Lander::landers(0);
float Lander:: NumberofLanders=0;
