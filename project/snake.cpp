//
// Created by viro on 2019-12-03.
//

#include "snake.h"

snake::snake(const sf::Vector2f& position, const sf::Vector2f& size)
{
    setSize(size);
    setPosition(position);
}

sf::Vector2f snake::getCurrentDirection() const
{
    return currentDirection;
}

void snake::setCurrentDirection(direction newDirection)
{
//    switch (newDirection)
//    {
//        case direction::up:
//            currentDirection = sf::Vector2f(0, -1);
//            break;
//        case direction::right:
//            currentDirection = sf::Vector2f(1, 0);
//            break;
//        case direction::down:
//            currentDirection = sf::Vector2f(0, 1);
//            break;
//        case direction::left:
//            currentDirection = sf::Vector2f(-1, 0);
//            break;
//    }
}
