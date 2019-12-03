#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

#if defined(__linux__)

#include "X11/Xlib.h"

#endif

#include "renderer.h"
#include "snake.h"

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
    snake snake1(sf::Vector2f(50, 50), sf::Vector2f(50, 50));
    std::list<sf::Drawable*> objects;
    objects.push_back(&snake1);

    // Graphics and event loop
    renderer gameRenderer(&window, objects);
    sf::Event event;
    while (window.isOpen())
    {

        auto snakeDirection = snake1.getCurrentDirection();
        switch (snakeDirection)
        {
            case direction::up:
                snake1.move(0, -1);
                break;
            case direction::right:
                snake1.move(1, 0);
                break;
            case direction::down:
                snake1.move(0, 1);
                break;
            case direction::left:
                snake1.move(-1, 0);
                break;
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
            && snakeDirection != direction::up)
        {
            snake1.setCurrentDirection(direction::down);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
            && snakeDirection != direction::down)
        {
            snake1.setCurrentDirection(direction::up);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
            && snakeDirection != direction::right)
        {
            snake1.setCurrentDirection(direction::left);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
            && snakeDirection != direction::left)
        {
            snake1.setCurrentDirection(direction::right);
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