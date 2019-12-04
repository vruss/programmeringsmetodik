#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "renderer.h"
#include "snake.h"
#include "utility.h"

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
            "SFML window",
            sf::Style::Close | sf::Style::Titlebar,
            settings
    );
    window.setVerticalSyncEnabled(true); // VSync
    window.setPosition(sf::Vector2i(0, 0));

    sf::Font font;
    if (!font.loadFromFile("resources/dejavu/DejaVuSans.ttf"))
        return EXIT_FAILURE;

    //
    // Create drawableObjects
    snake snake(sf::Vector2f(100, 100), sf::Vector2f(50, 4));
    snake.setOrigin(25, 2);

    sf::Text snakeCoordinatesText(snake.getStringPosition(), font, 12);
    sf::Text snakeRotationText(snake.getStringRotation(), font, 12);
    snakeRotationText.setPosition(0, 20);

    //
    // Push drawable objects to rendering pool
    std::list<sf::Drawable*> drawableObjects;
    drawableObjects.push_back(&snake);
    drawableObjects.push_back(&snakeCoordinatesText);
    drawableObjects.push_back(&snakeRotationText);

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
        sf::Vector2f direction;
        float rotation = utility::degToRad(snake.getRotation());
        direction.x = std::cos(rotation) * M_SPEED;
        direction.y = std::sin(rotation) * M_SPEED;
        snake.move(direction);

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