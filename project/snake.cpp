//
// Created by Viktor Rosvall (viro1702) on 2019-12-03.
// Student at Mid Sweden University.
//
// Course name: DT047G Programming Methodology
// File name: snake.cpp
//

#include <cmath>
#include "snake.h"
#include "utility.h"

snake::snake(const sf::Vector2f& position, const sf::Vector2f& size)
{
    setSize(size);
    setPosition(position);
}

std::string snake::getStringPosition() const
{
    std::string xPos = std::to_string(sf::Transformable::getPosition().x);
    std::string yPos = std::to_string(sf::Transformable::getPosition().y);
    return "x: " + xPos + " y: " + yPos;
}

std::string snake::getStringRotation() const
{
    std::string rotation = std::to_string(sf::Transformable::getRotation());
    return "r: " + rotation;
}

void snake::moveForward(float speedAmplifier)
{
    sf::Vector2f direction;
    float rotation = utility::degToRad(getRotation());
    direction.x = std::cos(rotation) * speedAmplifier;
    direction.y = std::sin(rotation) * speedAmplifier;
    move(direction);
}

void snake::grow()
{
    sf::RectangleShape newTail(sf::Vector2f(50,50));
    newTail.setOrigin(25,25);
    newTail.setPosition(getPosition() - sf::Vector2f(55,55));
    tail.push_back(newTail);
}
