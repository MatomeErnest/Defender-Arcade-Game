#ifndef STRINGS_H
#define STRINGS_H

#include <SFML/Graphics.hpp>
#include <tuple>
#include "Fonts.h"
#include <iostream>
#include <vector>

using namespace std;


using StringVector=vector<sf::Text*>;
class GameStrings
{
public:
GameStrings();
//Return iterators to vectors containing sf::strings
StringVector GameOver();
sf::Text* WelcomeMessage();
sf::Text* LossMessage();
sf::Text* VictoryMessage();
sf::Text* shield();
sf::Text* shield(string &shieldLevel);


sf::Text* PlayText();
sf::Text* SpaceShipFuel(int& fuellevel);

 static StringVector gameinstructions;
 static StringVector EndGameIntructions;

private:
Fonts fonts;
StringVector gameover_;

//instructions for game
string PlayerInstruction1_="Press UP key to move up";
string PlayerInstruction2_="Press DOWN key to move Down";
string PlayerInstruction3_="Press LEFT key to move to the Left";
string PlayerInstruction4_="Press RIGHT key to move the Right";
string PlayerInstruction5_="Press Spacebar to fire the Enemies";
string PlayerInstruction6_="Play";
string PlayerInstructions7_="Click Play To Start the game";
string PlayerInstructions8_="Press S key to activate shield";
string PlayerInstructions9_="Collide with the Humanoid to save it";
//Name of the game
string GameName_="The Defender";
//Constant message for the end-game splash
string GameOverMessage_="Game Over!";
string ContinueMessage_="Press R key to restart the game";
//Non constant message
string lossMessage_="You Lost!";
string VictoryMessage_="You Won!";
string CurrentScore_="You Score: ";
string highestScore_="Highest score: ";

string FuelLevel="Fuel: ";
string ShieldsLevel_="Shields:";
// 
sf::Text text1_;
sf::Text text2_;
sf::Text text3_;
sf::Text text4_;
sf::Text text5_;
sf::Text text6_;
sf::Text text7_;
sf::Text text8_;
sf::Text text9_;
sf::Text text10_;
sf::Text VictoryText_;
sf::Text LossText_;
sf::Text ScoreText_;
sf::Text HighScoreText_;
sf::Text PlayText_;
sf::Text ShieldText_;
sf::Text shield_;
sf::Text ShipFuel;
};
#endif