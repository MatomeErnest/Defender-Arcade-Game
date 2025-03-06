#include "ScoringSystem.h"

ScoringSystem::ScoringSystem()
{

}

void ScoringSystem:: IncrementScore(int score)
{
    currentscore+=score;
}

sf::Text* ScoringSystem:: CurrentScore()
{
 CurrentScoreFont=*(fonts.GameName());
auto Score=to_string(currentscore);
auto TheScore=CurrentScore_+Score;
ScoreText_.setFont(CurrentScoreFont);
ScoreText_.setString(TheScore);
ScoreText_.setScale(1.5f,1.5f);
ScoreText_.setFillColor(sf::Color::Yellow);
ScoreText_.setPosition(350.f,10.f);

return &ScoreText_;
}

sf::Text* ScoringSystem:: HighestScore()
{
    fstream myfile;
    myfile.open("resources/HighestScore.txt",ios::in);
    if(myfile.is_open())
    {
        myfile>>highestscore;
    }
    myfile.close();
    CurrentScoreFont=*(fonts.GameName());
 
    auto HighScoreString=to_string(highestscore);
    auto HighestScoreString=highestScore_+HighScoreString;
    HighScoreText_.setFont(CurrentScoreFont);
    HighScoreText_.setString(HighestScoreString);
    HighScoreText_.setFillColor(sf::Color::Magenta);
     HighScoreText_.setPosition(1100.f,10.f);

    return &HighScoreText_;
}

void ScoringSystem:: UpdateHighestScore()
{
    fstream myfile;
    myfile.open("resources/HighestScore.txt",ios::in);
    if(myfile.is_open())
    {
        myfile>>highestscore;
        
    }
    myfile.close();
    
    if(highestscore<currentscore)
    {
        highestscore=currentscore;
        myfile.open("resources/HighestScore.txt",ios::out);
        if(myfile.is_open())
        {
            myfile<<currentscore;
        }

        myfile.close();
    }
}

int ScoringSystem::currentscore=0;
int ScoringSystem::highestscore=0;