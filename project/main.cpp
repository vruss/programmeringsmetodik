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

    sf::Font font;
    if (!font.loadFromFile("resources/dejavu/DejaVuSansMono.ttf"))
        return EXIT_FAILURE;


    float snakeScale = 24;
    sf::Vector2f snakeSize(videoMode.height / snakeScale, videoMode.height / snakeScale);
    //
    // Create drawableObjects
    auto snake1 = std::make_shared<snake>(sf::Vector2f(100, 100), snakeSize, sf::Keyboard::A, sf::Keyboard::D);
    snake1->setOrigin(snakeSize.x / 2, snakeSize.y / 2);

    auto snake2 = std::make_shared<snake>(sf::Vector2f(100, 300), snakeSize, sf::Keyboard::Left, sf::Keyboard::Right);
    snake2->setOrigin(snakeSize.x / 2, snakeSize.y / 2);

    std::vector<std::shared_ptr<snake>> snakes;
    snakes.emplace_back(snake1);
    snakes.emplace_back(snake2);

    //
    // Push drawable objects to rendering pool
    std::vector<std::shared_ptr<sf::Drawable>> drawableObjects;
    drawableObjects.insert(drawableObjects.begin(), snakes.begin(), snakes.end());


    //
    // Graphics and event loop
    renderer gameRenderer(&window, drawableObjects);
    sf::Event event;
    while (window.isOpen())
    {
        for (const auto& snake: snakes)
        {
            snake->isColliding(snakes);
            snake->handleInput();
            snake->moveForward(M_SPEED);
        }

        // EVENT HANDLING
        while (window.pollEvent(event))
        {
            snake1->handleEvents(event);

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