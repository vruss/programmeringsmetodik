#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

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
    //
    // Game wide settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // Get list of preferred resolutions and BPP, ordered best first
    auto videoModes = sf::VideoMode::getFullscreenModes();

    // Create a window with resolution slightly lower than full
    sf::RenderWindow window(
            videoModes[9],
            "SFML Snake",
            sf::Style::Close | sf::Style::Titlebar,
            settings
    );
    window.setVerticalSyncEnabled(true); // VSync
    window.setPosition(sf::Vector2i(0, 0));

    sf::Font font;
    if (!font.loadFromFile("resources/dejavu/DejaVuSansMono.ttf"))
        return EXIT_FAILURE;

    //
    // Create drawableObjects
    snake snake(sf::Vector2f(100, 100), sf::Vector2f(50, 50));
    snake.setOrigin(25, 25);

    sf::Text snakeCoordinatesText(snake.getStringPosition(), font, 16);
    sf::Text snakeRotationText(snake.getStringRotation(), font, 16);
    snakeRotationText.setPosition(0, 40);

    //
    // Push drawable objects to rendering pool
    std::list<sf::Drawable*> drawableObjects;
    drawableObjects.push_back(&snake);
    drawableObjects.push_back(&snakeCoordinatesText);
    drawableObjects.push_back(&snakeRotationText);

    snake.grow();


    //
    // Graphics and event loop
    renderer gameRenderer(&window, drawableObjects);
    sf::Event event;
    while (window.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            snake.rotate(-T_RATE);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            snake.rotate(T_RATE);
        }
        snake.moveForward(M_SPEED);

        // EVENT HANDLING
        while (window.pollEvent(event))
        {
            eventHandler(event, window);
        }

        // Update debug text
        snakeCoordinatesText.setString(snake.getStringPosition());
        snakeRotationText.setString(snake.getStringRotation());

        // GAME RENDERING
        gameRenderer.draw();
    }

    return EXIT_SUCCESS;
}