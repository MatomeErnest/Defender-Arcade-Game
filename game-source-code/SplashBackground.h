#ifndef SPLASHBACKGROUNDTEXTURE_H
#define SPLASHBACKGROUNDTEXTURE_H
#include "Textures.h"
#include "Dimensions.h"


class SplashBackground
{
    public:
        SplashBackground();
        sf::Sprite* Background();
        sf::VertexArray Upperline();
       

    private:

        sf::Sprite background;
        Textures texture;
        float lineHeight;
        Dimensions dimensions;

};

#endif