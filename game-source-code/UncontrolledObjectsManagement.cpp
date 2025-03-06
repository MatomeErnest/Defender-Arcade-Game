#include "UnControlledObjectsManagement.h"

UnControlledObjects:: UnControlledObjects()
{
//////////////Creation Of the Five Humanoids/////////////////////////////////
    for(auto i=0;i<5;i++)
    {
        shared_ptr<Humanoid>TheHumanoid=make_shared<Humanoid>();
        TheHumanoid->CreateObject();
        humanoid.Humanoids.push_back(TheHumanoid);
    }

//////////////////////////////////////////////////////////////////////////////
    Finish=false;
    LanderDelay=T.asSeconds();
    clock.restart();
    
    ShootingDelay=T1.asSeconds();
    clock1.restart();

    Position=sf::Vector2f(20.f,832.f);


    fuel.CreateGasPump();
    GasPumpDelay=T2.asSeconds();
    clock2.restart();

    FuelDecayDelay=T3.asSeconds();
    clock3.restart();

    shields.CreateShields();
    shieldsDelay=T4.asSeconds();  
   
}
void UnControlledObjects:: UncontrolledObjectsManagement()
{
    // if(fuelmonitor.GasLevel()<=0)
    // {
    //     (*ship.TheShip.begin())->OutOfFuel=true;
    // }

    if(shields.isShieldActive)
    {
        
    if(shields.clock4.getElapsedTime().asSeconds()>=shields.getshieldsDelay())
      {
        shields.isShieldActive =false;
        spaceship.isInvulnerable=false;
       // Deactivate the oldest shield circle
       shields.removelastshield();
       (*spaceship.TheShip.begin())->OriginalColor();
       }
 
    }

    if(clock2.getElapsedTime().asSeconds()>=GasPumpDelay)
    {
        if(!fuel.GasPumpExists)
        {
            fuel.GasPumpExists=true; 
        }else
        {
            fuel.GasPumpExists=false; 
        }
        clock2.restart();
       
    }

    if(clock3.getElapsedTime().asSeconds()>=FuelDecayDelay&&!ship.OutOfFuel)
    {
        fuelmonitor.ConsumeGas();
        clock3.restart();
    }

//////////////////The creation of enemies must be timed/delayed//////////////////
    if(clock.getElapsedTime().asSeconds()>=LanderDelay&&lander.NumberofLanders<6)
    {
        
        if(lander.NumberofLanders>0.f&&!Finish)
        {
            if(lander.landers.size()==5&&Finish==false)
            {
                Finish=true;
            }
 
            
            for(auto LanderIter=lander.landers.begin();LanderIter<lander.landers.end();LanderIter++)
            {
                if(!(*LanderIter)->HasTarget)
                {
                    for(auto HumanoidIter=humanoid.Humanoids.begin();HumanoidIter<humanoid.Humanoids.end();HumanoidIter++)
                    {
                        if(!((*HumanoidIter)->Targeted))
                        {
                            
                            (*LanderIter)->Target=(*HumanoidIter).get();
                            (*LanderIter)->HasTarget=true;
                            

                            (*HumanoidIter)->Targeted=true;
                        
                            break;
                    
                        }
                       
                    }

                }
              
            
            }

           
        }else if(Finish&&lander.NumberofLanders<6)
        {
            Finish=false;
        }
        if(lander.NumberofLanders<=4)
        {
           Enemy1.EnemyCreation();///SHOULD SET RANDOM POSITION 
        }
         
        clock.restart();   
 
    }else if(lander.NumberofLanders>=6)//nolonger creating enemies.Just to assign free landers to free humanoids
    {

        for(auto LanderIter=lander.landers.begin();LanderIter<lander.landers.end();LanderIter++)
        {
            if(!(*LanderIter)->HasTarget)
            {
                for(auto HumanoidIter=humanoid.Humanoids.begin();HumanoidIter<humanoid.Humanoids.end();HumanoidIter++)
                {
                    if(!((*HumanoidIter)->Targeted))
                    {
                            
                        (*LanderIter)->Target=(*HumanoidIter).get();
                        (*LanderIter)->HasTarget=true;
                            

                        (*HumanoidIter)->Targeted=true;
                        
                        break;
                    
                    }
                       
                }

            }
              
            
        }


    }

    
////////////////////////////////////makes the landers constantly shoot//////////////////////// 
     if(lander.NumberofLanders>0.f)
    {
            auto Iter=lander.landers.begin()+shifter;
            
            if(clock1.getElapsedTime().asSeconds()>=ShootingDelay)
            {
                
                shifter++;  
                if(shifter<lander.landers.size())
                {  
                    (*(*Iter)).ShootMissile();
                    clock1.restart();
                }else
                {
                    shifter=0;
                    clock1.restart();
                }
                
            }        
    }
/////////////////////////////////////Constantly move uncontrolled objects////////////////////////////
  moveuncontrolled.MoveObjects();
}

int UnControlledObjects::numberofenemies=0;
sf::Clock UnControlledObjects:: clock=sf::Clock{};
sf::Clock UnControlledObjects:: clock1=sf::Clock{};
sf::Clock UnControlledObjects:: clock2=sf::Clock{};
sf::Clock UnControlledObjects:: clock3=sf::Clock{};
sf::Clock UnControlledObjects:: clock4=sf::Clock{};
int UnControlledObjects:: shifter=0;
int UnControlledObjects:: Advancer=0;
