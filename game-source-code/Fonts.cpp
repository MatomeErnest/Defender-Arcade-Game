#include "Fonts.h"

Fonts::Fonts()
{
    gamename.loadFromFile("resources/GameName.ttf");
    gameover.loadFromFile("resources/GameOver.ttf");
    gameinstructions.loadFromFile("resources/GameInstructions.ttf");
    loss.loadFromFile("resources/YouLost.ttf");
    highestscore.loadFromFile("resources/HighestScore.otf");
    playbutton.loadFromFile("resources/Play.ttf");
    Shields_.loadFromFile("resources/GameName.ttf");
}
sf::Font* Fonts:: GameName()
{
    //
    return &gamename;
}

sf::Font* Fonts:: GameOver()
{
    return &gameover;
}

sf::Font* Fonts:: GameInstructions()
{
    return &gameinstructions;
}

sf::Font* Fonts:: HighestScore()
{
    return &highestscore;
}
sf::Font* Fonts:: Loss()
{
    return &loss;
}

sf::Font* Fonts:: PlayButton()
 {

    return &playbutton;
 }

sf::Font* Fonts::Shields()
 {
    return &Shields_;
 }