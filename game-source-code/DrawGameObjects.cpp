#include "DrawGameObjects.h"

 void DrawGameObjects:: DrawObjects(std::shared_ptr<sf::RenderWindow>thewindow)
 {
    
    if((gamestatus.gameplay)&&(!gamestatus.beginning)&&(!gamestatus.GameEnd))
    {
      drawstars(thewindow);
      
      

      drawship(thewindow);
      DrawLaser(thewindow);
      DrawLander(thewindow);
      DrawMissile(thewindow);
      DrawHumanoids(thewindow);

      DrawScores(thewindow);
      DrawFuelPump(thewindow);
      DrawFuelLevels(thewindow);
      DrawShields(thewindow);
      DrawDividingLines(thewindow);

      
    }else if((!gamestatus.gameplay) && (gamestatus.beginning)&& (!gamestatus.GameEnd))
    {
      DrawSplashScreen(thewindow);

    }else if((!gamestatus.gameplay) && (!gamestatus.beginning)&& (gamestatus.GameEnd))
    {
      DrawEndGameScreen(thewindow);
    }
    
 }

 void DrawGameObjects:: drawship(std::shared_ptr<sf::RenderWindow>thewindow)
 {
  for(auto Iter=spaceship.TheShip.begin();Iter<spaceship.TheShip.end();Iter++)
  {
    DrawMobileObjects((*(*Iter)),thewindow);
  }
 }

void DrawGameObjects:: DrawLaser(std::shared_ptr<sf::RenderWindow>thewindow)
{
  for(auto Iter=laser.bulletsvector.begin();Iter<laser.bulletsvector.end();Iter++)
  {
    DrawMobileObjects((*(*Iter)),thewindow);
  }
}

void DrawGameObjects:: DrawLander(std::shared_ptr<sf::RenderWindow>thewindow)
{
  for(auto Iter=lander.landers.begin();Iter<lander.landers.end();Iter++)
  {
    DrawMobileObjects((*(*Iter)),thewindow);
  }
}

void DrawGameObjects:: DrawMissile(std::shared_ptr<sf::RenderWindow>thewindow)
{
  for(auto Iter=missile.Missiles.begin();Iter<missile.Missiles.end();Iter++)
  {
    DrawMobileObjects((*(*Iter)),thewindow);
  }
}


void DrawGameObjects:: DrawHumanoids(std::shared_ptr<sf::RenderWindow>thewindow)
{
  for(auto Iter=humanoid.Humanoids.begin();Iter<humanoid.Humanoids.end();Iter++)
  {
    DrawMobileObjects((*(*Iter)),thewindow);
  }
}


void DrawGameObjects:: drawstars(std::shared_ptr<sf::RenderWindow>thewindow)
{
  //cout <<"NUmber of stars"<<stars.StarVertices.getVertexCount()<<endl;
  thewindow->draw((stars.StarVertices));

}

void DrawGameObjects:: DrawDividingLines(std::shared_ptr<sf::RenderWindow>thewindow)
{
  thewindow->draw(splashbackground.Upperline());
}

void DrawGameObjects:: DrawSplashScreen(std::shared_ptr<sf::RenderWindow>thewindow)
{
    
    thewindow->draw(*(splashbackground.Background()));
    for(auto Iter=strings.gameinstructions.begin();Iter<strings.gameinstructions.end();Iter++)
    {
        
        thewindow->draw(*(*Iter));
    }
    thewindow->draw(*(strings.PlayText()));

}

void DrawGameObjects:: DrawEndGameScreen(std::shared_ptr<sf::RenderWindow>thewindow)
{
  thewindow->draw(*(splashbackground.Background()));
  for(auto Iter=strings.EndGameIntructions.begin();Iter<strings.EndGameIntructions.end();Iter++)
  {
        
    thewindow->draw(*(*Iter));
  }
  if(gamestatus.victory)
  {
    thewindow->draw(*(strings.VictoryMessage()));
  }else if(gamestatus.loss)
  {
    thewindow->draw(*(strings.LossMessage()));
  }

}

void DrawGameObjects:: DrawFuelPump(std::shared_ptr<sf::RenderWindow>thewindow)
{
  if(fuel.GasPumpExists)
  {
    thewindow->draw(fuel.gaspump);
  }

}
void DrawGameObjects:: DrawFuelLevels(std::shared_ptr<sf::RenderWindow>thewindow)
{
  thewindow->draw(*(fuelmonitor.FuelLevel()));
}

void DrawGameObjects:: DrawScores(std::shared_ptr<sf::RenderWindow>thewindow)
{
  thewindow->draw(*(scoresystem.CurrentScore()));
  thewindow->draw(*(scoresystem.HighestScore()));
}


 void DrawGameObjects:: DrawMobileObjects(MobileObject& mobileobject,WindowPtr thewindow)
 {
    thewindow->draw(*mobileobject.TheSprite());  
 }

 void DrawGameObjects:: DrawShields(std::shared_ptr<sf::RenderWindow>thewindow)
{
   
  
   for(auto Iter=shield.activeShields.begin();Iter<shield.activeShields.end();++Iter)
   {
           thewindow->draw(*Iter); // Draw each circle directly
   }

  thewindow->draw(*(strings.shield()));
}