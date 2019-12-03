//
// Created by viro on 2019-12-03.
//

#ifndef PROJECT_SNAKE_H
#define PROJECT_SNAKE_H


#include <SFML/System.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

enum class direction
{
    up,
    right,
    down,
    left,
};

class snake : public sf::RectangleShape
{
private:
    direction currentDirection = direction::right;

public:
    explicit snake(const sf::Vector2f& position, const sf::Vector2f& size);

    direction getCurrentDirection() const;

    void setCurrentDirection(direction newDirection);
};


#endif //PROJECT_SNAKE_H
