//
// Created by Viktor Rosvall (viro1702) on 2019-12-03.
// Student at Mid Sweden University.
//
// Course name: DT047G Programming Methodology
// File name: renderer.cpp
//

#include "renderer.h"

renderer::renderer(sf::RenderWindow* window, const std::vector<sf::Drawable*>& objects)
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


