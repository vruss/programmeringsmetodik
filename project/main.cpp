#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

#if defined(__linux__)

#include "X11/Xlib.h"

#endif

#include "renderer.h"

void eventHandler(sf::Event& event, sf::RenderWindow& window)
{
    // Close window: exit
    if (event.type == sf::Event::Closed
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        std::cout << "close event\n";
        window.close();
    }
}

int main()
{
    // Required for multi-threaded linux Xlib compilation
#if defined(__linux__)
    XInitThreads();
#endif

    // Get list of preferred resolutions and BPP, ordered best first
    auto videoModes = sf::VideoMode::getFullscreenModes();

    // Create a window with resolution slightly lower than full
    sf::RenderWindow window(
            videoModes[9],
            "SFML window",
            sf::Style::Close | sf::Style::Titlebar
    );
    window.setVerticalSyncEnabled(true); // VSync
    window.setPosition(sf::Vector2i(0, 0));

    // Create objects to be drawn
    sf::RectangleShape rectangleShape(sf::Vector2f(50.0f, 50.0f));
    std::list<sf::Drawable*> objects;
    objects.push_back(&rectangleShape);


    // Graphics and event loop
    renderer gameRenderer(&window, objects);
    sf::Event event;
    while (window.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            rectangleShape.move(0, 1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            rectangleShape.move(0, -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            rectangleShape.move(-1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            rectangleShape.move(1, 0);
        }


        // EVENT HANDLING
        while (window.pollEvent(event))
        {
            eventHandler(event, window);
        }


        // GAME RENDERING
        gameRenderer.draw();
    }

    return EXIT_SUCCESS;
}