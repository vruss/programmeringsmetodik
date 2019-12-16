#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>

#include "renderer.h"
#include "snake.h"
#include "utility.h"
#include "food.h"

//TODO: https://github.com/SFML/SFML/wiki/Tutorial%3A-Manage-dynamic-key-binding

int main()
{
    //
    // Game wide settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    int videoModeSize = 8;

    // Get list of preferred resolutions and BPP, ordered best first
    auto videoModes = sf::VideoMode::getFullscreenModes();
    auto videoMode = videoModes[videoModeSize];

    // Create a window with resolution slightly lower than full
    sf::RenderWindow window(
            videoMode,
            "SFML Snake",
            sf::Style::Close | sf::Style::Titlebar,
            settings
    );
    window.setVerticalSyncEnabled(true); // VSync
    window.setPosition(sf::Vector2i(0, 0));

    // Snake settings
    float snakeScale = 28;
    sf::Vector2f snakeSize(videoMode.height / snakeScale, videoMode.height / snakeScale);
    float snakeSpeed = snakeSize.x / snakeScale * 1.5;

    // Food settings
    float foodScale = snakeScale * 1.5;
    sf::Vector2f foodSize(videoMode.height / foodScale, videoMode.height / foodScale);
    int maxFood = videoMode.height / foodScale;

    //
    // Create drawableObjects
    auto snake1 = std::make_shared<snake>(utility::getRandomPosition(window.getSize()), snakeSize,
                                          sf::Keyboard::A, sf::Keyboard::D,
                                          sf::Color::Cyan);
    auto snake2 = std::make_shared<snake>(utility::getRandomPosition(window.getSize()), snakeSize,
                                          sf::Keyboard::Left, sf::Keyboard::Right,
                                          sf::Color::Green);
    // Fill player snakes
    std::vector<std::shared_ptr<snake>> snakes({snake1, snake2});

    // Fill food bowl
    std::vector<std::shared_ptr<food>> foodBowl(maxFood);
    std::generate(foodBowl.begin(), foodBowl.end(), [&foodSize, &window]
    {
        return std::make_shared<food>(foodSize, utility::getRandomPosition(window.getSize()));
    });


    //
    // Push drawable objects to rendering pool
    std::vector<std::shared_ptr<sf::Drawable>> drawableObjects;
    drawableObjects.insert(drawableObjects.begin(), snakes.begin(), snakes.end());
    drawableObjects.insert(drawableObjects.begin(), foodBowl.begin(), foodBowl.end());


    //
    // Graphics and event loop
    sf::Event event;
    renderer gameRenderer(&window, drawableObjects);
    while (window.isOpen())
    {
        for (const auto& _snake: snakes)
        {
            // Check snake collision
            if (_snake->isColliding(snakes))
            {
                _snake->reset(utility::getRandomPosition(window.getSize()));
            }
            // Check food collision
            if (auto foodPiece = _snake->isColliding(foodBowl))
            {
                _snake->grow();
                foodPiece->getFoodShape().setPosition(utility::getRandomPosition(window.getSize()));
            }
            _snake->handleInput();
            _snake->moveForward(snakeSpeed);
        }

        // EVENT HANDLING
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyReleased)
            {
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

        // GAME RENDERING
        gameRenderer.draw();
    }

    return EXIT_SUCCESS;
}