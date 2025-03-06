#include "GameEvents.h"    
    
GameEvents::GameEvents()
{
    
//Ship.CreateObject();
auto spaceship=make_shared<SpaceShip>();
spaceship->CreateObject();
Ship.TheShip.push_back(spaceship);
stars.MakeStarField();

}
void GameEvents::PollEvents(std::shared_ptr<sf::RenderWindow>thewindow)
{
    // if(Ship.OutOfFuel)
    // {
    //   //spaceship.shipdirection_=Directions::DOWN;
    //   Ship.TheSprite().move(0.f,1.f);
    //   //cout <<"Came"<<endl;
    // }

while(thewindow->pollEvent(this->ev))
        {
            switch(this->ev.type)
            {
        case sf::Event::Closed:
           scores.UpdateHighestScore();
           thewindow->close();
            break;

        case sf::Event::KeyPressed:
            if(this->ev.key.code==sf::Keyboard::Space&&gamestatus.gameplay)
            {
                (*Ship.TheShip.begin())->Shoot();

            }else if(this->ev.key.code==sf::Keyboard::Escape)
            {
               scores.UpdateHighestScore();
                thewindow->close(); 

            }else if(this->ev.key.code==sf::Keyboard::Right&&gamestatus.gameplay&&!((*Ship.TheShip.begin())->OutOfFuel))
            {   
               // KeyHeldDown=true;
               (*Ship.TheShip.begin())->TurnRight();  
               Ship.ShipMoved=true;
                (*Ship.TheShip.begin())->shipglobaldirection=Directions::RIGHT;
                (*Ship.TheShip.begin())->MoveObject();
                stars.MoveLeft();
                
            
  
            }else  if(this->ev.key.code==sf::Keyboard::Left&&gamestatus.gameplay&&!((*Ship.TheShip.begin())->OutOfFuel))
            {
                (*Ship.TheShip.begin())->TurnLeft();
                (*Ship.TheShip.begin())->shipglobaldirection=Directions::LEFT;
                Ship.ShipMoved=true;
               (*Ship.TheShip.begin())->MoveObject();
                stars.MoveRight();
             
             
            }else  if(this->ev.key.code==sf::Keyboard::Up&&gamestatus.gameplay&&!((*Ship.TheShip.begin())->OutOfFuel))
            {
                (*Ship.TheShip.begin())->shipglobaldirection=Directions::UP;
                Ship.ShipMoved=true;
                (*Ship.TheShip.begin())->MoveObject();
                 
                  
            }else if(this->ev.key.code==sf::Keyboard::Down&&gamestatus.gameplay&&!((*Ship.TheShip.begin())->OutOfFuel))
            {
                (*Ship.TheShip.begin())->shipglobaldirection=Directions::DOWN;
                Ship.ShipMoved=true;
                (*Ship.TheShip.begin())->MoveObject();
                
            }else if(this->ev.key.code==sf::Keyboard::S && gamestatus.gameplay)
            {
                shields.activateShields(*(*Ship.TheShip.begin()));
               
            }
            else if(this->ev.key.code==sf::Keyboard::R&&!gamestatus.gameplay&&gamestatus.GameEnd&&!gamestatus.beginning)
            {
                gamestatus.RestartGame();

                
            }
         case sf::Event::MouseButtonPressed:
            sf::Vector2i mousePosition = sf::Mouse::getPosition(*thewindow);
            sf::FloatRect playBounds = (*(gamestring.PlayText())).getGlobalBounds();

            if (playBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))&&!gamestatus.gameplay&&
            !gamestatus.GameEnd) 
            {

                gamestatus.gameplay=true;
                gamestatus.beginning=false;
            }       
            break;
        
            }
        }

}

