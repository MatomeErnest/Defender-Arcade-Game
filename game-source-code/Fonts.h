#ifndef FONTS_H
#define FONTS_H

#include <SFML/Graphics.hpp>
class Fonts
{
public:
    Fonts();
    sf::Font* GameName();
    sf::Font* GameOver();
    sf::Font* GameInstructions();
    sf::Font* HighestScore();
    sf::Font* Loss();
    sf::Font* PlayButton();
    sf::Font* Shields();
    
private:
    sf::Font gamename;
    sf::Font gameover;
    sf::Font gameinstructions;
    sf::Font highestscore;
    sf::Font loss;
    sf::Font playbutton;
    sf::Font Shields_;
};
#endif