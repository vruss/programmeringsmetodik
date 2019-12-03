//
// Created by viro on 2019-12-03.
//

#include "snake.h"

snake::snake(const sf::Vector2f& position, const sf::Vector2f& size)
{
    setSize(size);
    setPosition(position);
}

direction snake::getCurrentDirection() const
{
    return currentDirection;
}

void snake::setCurrentDirection(direction newDirection)
{
    snake::currentDirection = newDirection;
}
