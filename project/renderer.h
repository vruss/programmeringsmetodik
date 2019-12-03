//
// Created by viro on 2019-12-03.
//

#ifndef PROJECT_RENDERER_H
#define PROJECT_RENDERER_H


#include <list>
#include <mutex>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class renderer
{
private:
    sf::RenderWindow* window;
    std::list<sf::Drawable*> objects;
    std::mutex* windowMutex;
    int* a;

    void draw();

public:
    renderer(sf::RenderWindow* window,
             const std::list<sf::Drawable*>& objects,
             int* a,
             std::mutex* windowMutex);

    renderer(std::mutex* windowMutex);

    renderer(const renderer& rhs);

    renderer(renderer&& rhs) noexcept;

    void swap(renderer& rhs);

    void operator()();
};


#endif //PROJECT_RENDERER_H
