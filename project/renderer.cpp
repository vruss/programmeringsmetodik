//
// Created by viro on 2019-12-03.
//

#include "renderer.h"

renderer::renderer(sf::RenderWindow* window, const std::list<sf::Drawable*>& objects)
        : objects(objects), window(window)
{
}

void renderer::draw()
{
    // Mandatory window clear
    window->clear();

    // Draw all objects
    for (const auto& object: objects)
    {
        window->draw(*object);
    }

    // Update the window
    window->display();
}


