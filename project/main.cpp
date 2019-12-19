#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "renderer.h"
#include "snake.h"
#include "utility.h"
#include "wallBuilder.h"
#include "collisionHandler.h"


int main()
{
    //
    // Game wide settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    int videoModeSize = 6;

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

    //
    // Object settings based on game resolution
    float snakeScale = 28;
    sf::Vector2f snakeSize(videoMode.height / snakeScale, videoMode.height / snakeScale);
    float snakeSpeed = snakeSize.x / snakeScale * 1.5;

    float foodScale = snakeScale * 1.5;
    sf::Vector2f foodSize(videoMode.height / foodScale, videoMode.height / foodScale);
    int maxFood = videoMode.height / foodScale * 1.25;

    //
    // Create snakes
    auto snake1 = std::make_shared<snake>(utility::getRandomPosition(window.getSize()), snakeSize,
                                          sf::Keyboard::A, sf::Keyboard::D,
                                          sf::Color::Cyan);
    auto snake2 = std::make_shared<snake>(utility::getRandomPosition(window.getSize()), snakeSize,
                                          sf::Keyboard::Left, sf::Keyboard::Right,
                                          sf::Color::Green);
    std::vector<std::shared_ptr<snake>> snakes({snake1, snake2});

    // Fill food bowl
    std::vector<std::shared_ptr<sf::RectangleShape>> foodBowl(maxFood);
    std::generate(foodBowl.begin(), foodBowl.end(), [&foodSize, &window]
    {
        auto foodPiece = std::make_shared<sf::RectangleShape>(foodSize);
        foodPiece->setPosition(utility::getRandomPosition(window.getSize()));
        foodPiece->setFillColor(sf::Color::Red);
        return foodPiece;
    });

    // Create walls
    wallBuilder _wallBuilder(snakeSize, window.getSize());
    std::vector<std::shared_ptr<sf::RectangleShape>> walls;
    walls.emplace_back(std::make_shared<sf::RectangleShape>(_wallBuilder.buildLeftWall()));
    walls.emplace_back(std::make_shared<sf::RectangleShape>(_wallBuilder.buildDownWall()));
    walls.emplace_back(std::make_shared<sf::RectangleShape>(_wallBuilder.buildRightWall()));
    walls.emplace_back(std::make_shared<sf::RectangleShape>(_wallBuilder.buildTopWall()));

    //
    // Push drawable objects to rendering pool
    std::vector<std::shared_ptr<sf::Drawable>> drawableObjects;
    drawableObjects.insert(drawableObjects.begin(), walls.begin(), walls.end());
    drawableObjects.insert(drawableObjects.begin(), snakes.begin(), snakes.end());
    drawableObjects.insert(drawableObjects.begin(), foodBowl.begin(), foodBowl.end());


    //
    // Graphics and event loop
    sf::Event event;
    renderer gameRenderer(&window, drawableObjects);
    collisionHandler _collisionHandler(foodBowl, walls, snakes, window.getSize());
    while (window.isOpen())
    {
        // SNAKE COLLISION CHECKS
        _collisionHandler.handleCollisions();

        // SNAKE INPUT LOGIC
        for (const auto& _snake: snakes)
        {
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