#ifndef SPRITEMOVEMENT_H
#define SPRITEMOVEMENT_H

#include "Textures.h"

class MobileObject
{
    public:
    //functions to move
        MobileObject();
        virtual void MoveLeft();
        virtual void MoveRight();
        virtual void MoveUp();
        virtual void MoveDown();
        virtual void CreateObject()=0;
        virtual void MoveObject()=0;
        virtual sf::Sprite* TheSprite();
        
    protected:
        float SpriteSpeed_;
        Textures texture;
        sf::Sprite thesprite;   
};

#endif