#include "SplashBackground.h"

SplashBackground:: SplashBackground()
{
    background.setTexture(*(texture.getIntroTexture()));
    lineHeight = 110.0f;

}
sf::Sprite* SplashBackground:: Background()
{
    return &background;
}

sf::VertexArray SplashBackground:: Upperline()
{
    sf::VertexArray line(sf::Lines, 2);
    line[0].position = sf::Vector2f(0, lineHeight);
    line[1].position = sf::Vector2f(dimensions.WindowWidth(), lineHeight);

    line[0].color = sf::Color::Red;
    line[1].color = sf::Color::Red;

    return line;
}