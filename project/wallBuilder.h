//
// Created by Viktor Rosvall (viro1702) on 2019-12-16.
// Student at Mid Sweden University.
// 
// Course name: DT047G Programming Methodology
// File name: wallBuilder.h 
//

#ifndef PROJECT_WALLBUILDER_H
#define PROJECT_WALLBUILDER_H


#include <SFML/System.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

/**
 * @brief   Class used to create walls around play area
 */
class wallBuilder
{
private:
    sf::Vector2f wallSize;
    sf::Vector2u roomSize;

public:

    /**
     * @brief   Constructs a wall builder
     *
     * @param wallSize  size of the walls
     * @param roomSize  the wall boundaries
     */
    wallBuilder(const sf::Vector2f& wallSize, const sf::Vector2u& roomSize);

    /**
     * @return  left wall piece
     */
    sf::RectangleShape buildLeftWall();

    /**
     * @return  left wall piece
     */
    sf::RectangleShape buildRightWall();

    /**
     * @return  top wall piece
     */
    sf::RectangleShape buildTopWall();

    /**
     * @return  down wall piece
     */
    sf::RectangleShape buildDownWall();
};


#endif //PROJECT_WALLBUILDER_H
