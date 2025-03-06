#ifndef SCORINGSYSTEM_H
#define SCORINGSYSTEM_H

#include "GameStrings.h"
#include "Fonts.h"
#include <fstream>
#include <iostream>

using namespace std;

class ScoringSystem
{
    public:
        ScoringSystem();
        static void IncrementScore(int score);
        sf::Text* CurrentScore();
        sf::Text* HighestScore();
        void UpdateHighestScore();
        static int currentscore;
        static int highestscore;
        
    private:
         
        Fonts fonts;
        sf::Font HighestScoreFont;
        sf::Font CurrentScoreFont;
        string CurrentScore_="Score: ";
        string highestScore_="HighestScore: ";
        sf::Text ScoreText_;
        sf::Text HighScoreText_;
};

#endif