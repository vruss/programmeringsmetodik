#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>

#if defined(__linux__)
#include "X11/Xlib.h"
#endif

sf::RectangleShape rectangle(sf::Vector2f(50.0f, 50.0f));

void renderingFunction(sf::RenderWindow* window)
{

    // activate the window's context
    window->setActive(true);

    // the rendering loop
    while (window->isOpen())
    {
        window->clear();
        window->draw(rectangle);

        // Update the window
        window->display();
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
    window.setActive(false);

    // Start rendering thread
    std::thread renderingThread(&renderingFunction, &window);

    // Event and logic loop
    sf::Event event;
    while (window.isOpen())
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            rectangle.move(0,1);
        }

        // Check all the window's events that were triggered since the last iteration of the loop
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed
                || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
                renderingThread.join();
            }
        }
    }
    return EXIT_SUCCESS;
}