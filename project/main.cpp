#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <list>
#include <mutex>

#if defined(__linux__)

#include "X11/Xlib.h"

#endif

#include "renderer.h"




//void renderingFunction(sf::RenderWindow* window)
//{
//
//    // activate the window's context
//    window->setActive(true);
//
//    // the rendering loop
//    while (window->isOpen())
//    {
//        window->clear();
//        window->draw(rectangle);
//
//        // Update the window
//        window->display();
//    }
//}
int* counter = new int(0);

void eventHandler(sf::Event& event, sf::RenderWindow& window, std::mutex& windowMutex)
{
    std::lock_guard<std::mutex> lockWindow(windowMutex);
    for(int i = 0; i < 100000; i++)
    {
        *counter = *counter + 1;
    }

//    // Close window: exit
//    if (event.type == sf::Event::Closed
//        || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//    {
//        window.close();
//    }
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

    sf::RectangleShape rectangleShape(sf::Vector2f(50.0f, 50.0f));
    std::list<sf::Drawable*> objects;
    objects.push_back(&rectangleShape);


    std::mutex windowMutex;


    // Start rendering thread
    std::cout << "Trying to start rendering thread\n";
    std::thread renderingThread(renderer(& window, objects, counter, &windowMutex));


    // Event and logic loop
    sf::Event event;
//    while (window.isOpen())
    {
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){}

//        rectangleShape.move(1, 1);

        // Check all the window's events that were triggered since the last iteration of the loop
//        while (window.pollEvent(event))
        {
            eventHandler(event, window, windowMutex);
//            // Close window: exit
//            if (event.type == sf::Event::Closed
//                || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//            {
//                window.close();
//            }
        }

    }
    renderingThread.join();

    std::cout << "ExitingExiting " << *counter << "\n";
    return EXIT_SUCCESS;
}