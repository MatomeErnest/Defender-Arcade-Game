#ifndef WINDOWS_H
#define WINDOWS_H

#include <SFML/Graphics.hpp>
#include <memory>

using namespace std;
using WindowPointer= shared_ptr<sf::RenderWindow>;
class Window
{
    public:
        Window();
        WindowPointer Screen();

    private:
        WindowPointer window;
        sf::VideoMode videomode;
};
#endif