//
// Created by Viktor Rosvall (viro1702) on 2019-12-04.
// Student at Mid Sweden University.
//
// Course name: DT047G Programming Methodology
// File name: utility.h
//

#ifndef PROJECT_UTILITY_H
#define PROJECT_UTILITY_H

#include <SFML/System.hpp>

/**
 * @brief   Class with basic utility functions
 *
 * This class contains basic utility and math functions such as
 * degree to radian conversions.
 */
struct utility
{
    /**
     * @brief   Converts degrees to radians
     *
     * @param degrees   input degrees
     * @return          output radians
     */
    static float degToRad(float degrees);

    /**
     * @brief   Converts radians to degrees
     *
     * @param radians   input radians
     * @return          output degrees
     */
    static float radToDeg(float radians);

    /**
     * @brief   Calculates a random float position inside a given bounds
     *
     * The function will return a 2D vector representing a position,
     * given bounds as an argument.
     *
     * @param bounds    the max position boundaries
     * @return          the new random position
     */
    static sf::Vector2f getRandomPosition(sf::Vector2u bounds);
};


#endif //PROJECT_UTILITY_H
