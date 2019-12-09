#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>

#include "renderer.h"
#include "snake.h"


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
    auto snakeObj = std::make_shared<snake>(sf::Vector2f(100, 100), sf::Vector2f(50, 50));
    snakeObj->setOrigin(25, 25);

    auto snakeDebugText = std::make_shared<sf::Text>(snakeObj->getDebugInformation(), font, 16);

    //
    // Push drawable objects to rendering pool
    std::vector<std::shared_ptr<sf::Drawable>> drawableObjects;
    drawableObjects.emplace_back(snakeObj);
    drawableObjects.emplace_back(snakeDebugText);


    //
    // Graphics and event loop
    renderer gameRenderer(&window, drawableObjects);
    sf::Event event;
    while (window.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            snakeObj->rotateRight(-T_RATE);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            snakeObj->rotateRight(T_RATE);
        }
        snakeObj->moveForward(M_SPEED);


        // EVENT HANDLING
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::G)
                {
                    snakeObj->grow();
                }
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }
            else if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Update debug text
        snakeDebugText->setString(snakeObj->getDebugInformation());

        // GAME RENDERING
        gameRenderer.draw();
    }

    return EXIT_SUCCESS;
}