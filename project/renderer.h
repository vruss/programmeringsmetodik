//
// Created by Viktor Rosvall (viro1702) on 2019-12-03.
// Student at Mid Sweden University.
//
// Course name: DT047G Programming Methodology
// File name: renderer.h
//

#ifndef PROJECT_RENDERER_H
#define PROJECT_RENDERER_H


#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>


/**
 * @brief   Class used to render objects to the screen
 */
class renderer
{
private:
    sf::RenderWindow* window;
    std::vector<std::shared_ptr<sf::Drawable>> objects;

public:

    /**
     * @brief Constructs a renderer for drawing objects.
     *
     * Constructs a renderer that will draw the passed in objects to the
     * window handle.
     *
     * @param window    handle used for drawing
     * @param objects   drawable objects to be drawn
     */
    explicit renderer(sf::RenderWindow* window, const std::vector<std::shared_ptr<sf::Drawable>>& objects);

    /**
     * @brief   Draws the objects to the screen
     */
    void draw();
};


#endif //PROJECT_RENDERER_H
