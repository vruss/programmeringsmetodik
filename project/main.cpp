#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Get preferred resolution and BPP
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    // Create a window with the same pixel depth as the desktop
    sf::RenderWindow window(
            desktop,
            "SFML window",
            sf::Style::Fullscreen
    );
    window.setVerticalSyncEnabled(true); // VSync


    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("resources/cute_image.jpeg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("resources/dejavu/DejaVuSerif.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Hello SFML", font, 50);


    // Start the game loop
    while (window.isOpen())
    {
        // Check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.draw(text);

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}