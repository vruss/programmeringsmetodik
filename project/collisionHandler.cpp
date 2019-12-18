//
// Created by Viktor Rosvall (viro1702) on 2019-12-18.
// Student at Mid Sweden University.
//
// Course name: DT047G Programming Methodology
// File name: collisionHandler.cpps
//

#include "collisionHandler.h"
#include "utility.h"

collisionHandler::collisionHandler(const std::vector<std::shared_ptr<sf::RectangleShape>>& foodBowl,
                                   const std::vector<std::shared_ptr<sf::RectangleShape>>& walls,
                                   const std::vector<std::shared_ptr<snake>>& snakes,
                                   const sf::Vector2u& playArea)
        : foodBowl(foodBowl), walls(walls), snakes(snakes), playArea(playArea)
{
}

void collisionHandler::handleCollisions()
{
    for (const auto& _snake: snakes)
    {
        handleSnakeToSnakeCollisions(_snake);
        handleSnakeToFoodCollisions(_snake);
        handleSnakeToWallCollisions(_snake);
    }
}

void collisionHandler::handleSnakeToSnakeCollisions(const std::shared_ptr<snake>& _snake)
{
    for (const auto& otherSnake: snakes)
    {
        if (otherSnake == _snake)
        {
            continue;
        }
        for (const auto& otherTail: otherSnake->getTail())
        {
            if (_snake->isColliding(otherTail))
            {
                _snake->reset(utility::getRandomPosition(playArea));
            }
        }
    }
}

void collisionHandler::handleSnakeToFoodCollisions(const std::shared_ptr<snake>& _snake)
{
    for (const auto& food: foodBowl)
    {
        if (_snake->isColliding(*food.get()))
        {
            _snake->grow();
            food->setPosition(utility::getRandomPosition(playArea));
        }
    }
}

void collisionHandler::handleSnakeToWallCollisions(const std::shared_ptr<snake>& _snake)
{
    for (const auto& wall: walls)
    {
        if (_snake->isColliding(*wall.get()))
        {
            _snake->reset(utility::getRandomPosition(playArea));
        }
    }
}

