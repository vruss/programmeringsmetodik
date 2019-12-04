//
// Created by Viktor Rosvall (viro1702) on 2019-12-03.
// Student at Mid Sweden University.
//
// Course name: DT047G Programming Methodology
// File name: snake.cpp
//

#include <cmath>
#include <iostream>
#include "snake.h"
#include "utility.h"

snake::snake(const sf::Vector2f& position, const sf::Vector2f& size)
        : tail()
{
    sf::RectangleShape rect(size);
    rect.setPosition(position);
    rect.setFillColor(sf::Color::Red);
    tail.push_back(rect);
    update();
}

std::string snake::getStringPosition() const
{
    std::string text;

    for (const auto& e : tail)
    {
        std::string xPos = std::to_string(e.getPosition().x);
        std::string yPos = std::to_string(e.getPosition().y);

        text.append("x: " + xPos + " y: " + yPos + "\n");
//        text += std::to_string(e.getPosition().y);
    }

//    std::string xPos = std::to_string(sf::Transformable::getPosition().x);
//    std::string yPos = std::to_string(sf::Transformable::getPosition().y);

    return text;
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

    for (auto& e : tail)
    {
        e.move(direction);
    }
    update();
}

void snake::grow()
{
    sf::RectangleShape newTail(sf::Vector2f(50, 50));
    newTail.setOrigin(25, 25);
//    newTail.setPosition(getPosition() - sf::Vector2f(55, 55));
    newTail.setFillColor(sf::Color::Green);
    tail.push_back(newTail);
    update();
}

size_t snake::getPointCount() const
{
    int points = 0;
    for (const auto& e : tail)
    {
        points += e.getPointCount();
    }
    std::cout << "points: " << points << "\n";
    return points;
}

sf::Vector2f snake::getPoint(std::size_t index) const
{
    size_t tailIndex = index / 4;
    size_t pointIndex = index % 4;

    std::cout << "tailIndex: " << tailIndex << "\n";
    std::cout << "pointIndex: " << pointIndex << "\n";
    return tail.at(tailIndex).getPoint(pointIndex);
}
