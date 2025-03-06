#include "GameStrings.h"

GameStrings::GameStrings()
{
    sf::Color customOrangeColor1(255, 140, 0); // Orange color
    text1_.setFont(*(fonts.GameInstructions()));
    text1_.setCharacterSize(20);
    text1_.setFillColor(customOrangeColor1);
    text1_.setString(PlayerInstruction1_);
    text1_.setPosition(150,300);
    gameinstructions.push_back(&text1_);
    
    sf::Color customOrangeColor2(255, 140, 0); // Orange color
    text2_.setFont(*(fonts.GameInstructions()));
    text2_.setCharacterSize(20);
    text2_.setFillColor(customOrangeColor2);
    text2_.setString(PlayerInstruction2_);
    text2_.setPosition(950,300);
    gameinstructions.push_back(&text2_);
    
    text3_.setFont(*fonts.GameInstructions());
    text3_.setCharacterSize(20);
     text3_.setFillColor(sf::Color::Green);
    text3_.setString(PlayerInstruction3_);
    text3_.setPosition(150,400);
    gameinstructions.push_back(&text3_);
    
    text4_.setFont(*fonts.GameInstructions());
    text4_.setCharacterSize(20);
    text4_.setFillColor(sf::Color::Green);
    text4_.setString(PlayerInstruction4_);
    text4_.setPosition(950,400);
    gameinstructions.push_back(&text4_);

    sf::Color PurpleColor(255, 0, 255); // Purple color
    text5_.setFont(*fonts.GameInstructions());
    text5_.setCharacterSize(20);
    text5_.setFillColor(PurpleColor);
    text5_.setString(PlayerInstruction5_);
    text5_.setPosition(500,500);
    gameinstructions.push_back(&text5_);

    PlayText_.setFont(*fonts.GameInstructions());
    PlayText_.setCharacterSize(80);
    PlayText_.setFillColor(sf::Color::Yellow);
    PlayText_.setString(PlayerInstruction6_);
    PlayText_.setPosition(650,700);
    
    text9_.setFont(*fonts.GameInstructions());
    text9_.setCharacterSize(20);
    text9_.setFillColor(sf::Color::Blue);
    text9_.setString(PlayerInstructions7_);
    text9_.setPosition(550,600);
    gameinstructions.push_back(&text9_);
    //Game name
    text6_.setFont(*fonts.GameName());
    text6_.setCharacterSize(70);
    text6_.setFillColor(sf::Color::Red);
     text6_.setString(GameName_);
    text6_.setPosition(430,30);
    //gameName_.setString("The Defender");
    gameinstructions.push_back(&text6_);
    ///////////////////////////////////////////////////////////////
    /*End Game splash messages*/
    text7_.setFont(*fonts.GameOver());
    text7_.setCharacterSize(70);
    text7_.setFillColor(sf::Color::Green);
    text7_.setString(GameOverMessage_);
    text7_.setPosition(350.f,400.f);
    EndGameIntructions.push_back(&text7_);

    ShieldText_.setFont(*fonts.GameInstructions());
    ShieldText_.setCharacterSize(20);
    ShieldText_.setFillColor(sf::Color::Cyan);
    ShieldText_.setString(PlayerInstructions8_);
    ShieldText_.setPosition(550,550);
    gameinstructions.push_back(&ShieldText_);

    text8_.setFont(*fonts.GameOver());
    text8_.setCharacterSize(70);
    text8_.setFillColor(sf::Color::Green);
    text8_.setString(ContinueMessage_);
    text8_.setPosition(350.f,600.f);
    EndGameIntructions.push_back(&text8_);

    text10_.setFont(*fonts.GameInstructions());
    text10_.setCharacterSize(20);
    text10_.setFillColor(sf::Color::Red);
    text10_.setString(PlayerInstructions9_);
    text10_.setPosition(470,450);
    gameinstructions.push_back(&text10_);


//Victory message
    VictoryText_.setFont(*fonts.PlayButton());
    VictoryText_.setCharacterSize(70);
    VictoryText_.setFillColor(sf::Color::White);
     VictoryText_.setString(VictoryMessage_);
    VictoryText_.setPosition(350.f,500.f);

//Loss message
    LossText_.setFont(*fonts.PlayButton());
    LossText_.setCharacterSize(70);
    LossText_.setFillColor(sf::Color::Magenta);
    LossText_.setString(lossMessage_);
    LossText_.setPosition(350.f,500.f);
}
StringVector GameStrings:: GameOver() 
{

    return gameover_;
}

sf::Text* GameStrings:: LossMessage()
{
   return &LossText_;
}
sf::Text* GameStrings:: VictoryMessage()
{
    return &VictoryText_;
}

sf::Text* GameStrings::PlayText()
{
   return &PlayText_;
}


sf::Text* GameStrings:: SpaceShipFuel(int& fuellevel)
{
    
    auto Fuel=to_string(fuellevel);
    auto Thefuel=FuelLevel+Fuel;
    ShipFuel.setFont(*(fonts.GameName()));
    ShipFuel.setString(Thefuel);
    ShipFuel.setScale(1.2f,1.2f);
    ShipFuel.setFillColor(sf::Color::White);
    ShipFuel.setPosition(780.f,10.f);

    return &ShipFuel;
}

sf::Text* GameStrings::shield()
{
    shield_.setFont(*(fonts.Shields()));
    shield_.setCharacterSize(35);
    shield_.setFillColor(sf::Color::Magenta);
    shield_.setString(ShieldsLevel_);
    shield_.setPosition(5,20.f);
    return &shield_;
}

StringVector GameStrings:: gameinstructions(0);
StringVector GameStrings:: EndGameIntructions(0);