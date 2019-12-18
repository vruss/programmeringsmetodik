//
// Created by Viktor Rosvall (viro1702) on 2019-12-18.
// Student at Mid Sweden University.
//
// Course name: DT047G Programming Methodology
// File name: collisionHandler.h
//

#ifndef PROJECT_COLLISIONHANDLER_H
#define PROJECT_COLLISIONHANDLER_H

#include <vector>
#include <memory>
#include <SFML/Graphics/RectangleShape.hpp>
#include "snake.h"

/**
 * @brief   Class that handles snake collisions
 */
class collisionHandler
{
private:
    std::vector<std::shared_ptr<sf::RectangleShape>> foodBowl;
    std::vector<std::shared_ptr<sf::RectangleShape>> walls;
    std::vector<std::shared_ptr<snake>> snakes;
    sf::Vector2u playArea;

    void handleSnakeToSnakeCollisions(const std::shared_ptr<snake>& _snake);

    void handleSnakeToFoodCollisions(const std::shared_ptr<snake>& _snake);

    void handleSnakeToWallCollisions(const std::shared_ptr<snake>& _snake);

public:

    /**
     * @brief   Constructs a collision handler
     *
     * It needs to know about all collidable objects in the game.
     *
     * @param foodBowl  collidable food pieces
     * @param walls     collidable walls
     * @param snakes    collidable snakes
     * @param playArea  respawn area
     */
    collisionHandler(const std::vector<std::shared_ptr<sf::RectangleShape>>& foodBowl,
                     const std::vector<std::shared_ptr<sf::RectangleShape>>& walls,
                     const std::vector<std::shared_ptr<snake>>& snakes,
                     const sf::Vector2u& playArea);

    /**
     * @brief   Handles all collisions
     */
    void handleCollisions();
};


#endif //PROJECT_COLLISIONHANDLER_H
