#include "Window.h"

Window::Window()
{
    this->videomode.height=900;
    this->videomode.width=1600;
    this->window=std::make_shared<sf::RenderWindow>(videomode,"The Defender");
    this->window->setFramerateLimit(60);
}
WindowPointer Window::Screen()
{
    return this->window;
}        

   