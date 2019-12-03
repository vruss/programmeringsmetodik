//
// Created by viro on 2019-12-03.
//

#include <iostream>
#include "renderer.h"

renderer::renderer(sf::RenderWindow* window, const std::list<sf::Drawable*>& objects, int* a, std::mutex* windowMutex)
        : window(window), objects(objects), a(a), windowMutex(windowMutex)
{
}

renderer::renderer(renderer&& rhs) noexcept
        : renderer(nullptr, std::list<sf::Drawable*>(), 0, std::mutex())
{
    swap(rhs); // swap rhs with null object
}

renderer::renderer(const renderer& rhs)
        : renderer(rhs.window, rhs.objects, rhs.a, rhs.windowMutex)
{
}

void renderer::operator()()
{
    std::cout << "Rendering loop active\n";
    // activate the window's context
    window->setActive(true);

    // the rendering loop
//    while (window->isOpen())
//    {
        draw();
//    }
    std::cout << "Rendering loop deactivated\n";
}


void renderer::swap(renderer& rhs)
{
    std::swap(window, rhs.window);
    std::swap(objects, rhs.objects);
    std::swap(a, rhs.a);
    std::swap(windowMutex, rhs.windowMutex);
}

void renderer::draw()
{
    std::lock_guard<std::mutex> lockWindow(*windowMutex);
    for(int i = 0; i < 100000; i++)
    {
        *a = *a + 1;
    }


//    window->clear();
//
//    for (const auto& object: objects)
//    {
//        window->draw(*object);
//    }
//
//    // Update the window
//    window->display();
}




