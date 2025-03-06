#ifndef STARS_H
#define STARS_H
#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <ctime>
#include "Dimensions.h"
#include <iostream>
using namespace std;

class Stars
{
    public:
        Stars();
        void MakeStarField();
        void MoveLeft();
        void MoveRight();
        sf::VertexArray StarField();
        static sf::VertexArray StarVertices;
    private:
        const int starCount=400;
        const float starSpeed=12.f;
        Dimensions dimensions;
};

#endif