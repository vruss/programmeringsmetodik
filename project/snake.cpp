//
// Created by Viktor Rosvall (viro1702) on 2019-12-03.
// Student at Mid Sweden University.
//
// Course name: DT047G Programming Methodology
// File name: snake.cpp
//

#include <cmath>
#include <iostream>
#include <SFML/Graphics/RenderTarget.hpp>

#include "snake.h"
#include "utility.h"

snake::snake(const sf::Vector2f& position, const sf::Vector2f& size)
        : tail()
{
    sf::RectangleShape rect(size);
    rect.setPosition(position);
    rect.setOrigin(size.x / 2, size.y / 2);
    rect.setFillColor(sf::Color::Red);
    tail.push_back(rect);
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

//TODO: Make snake rotate entire body
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
}

void snake::grow()
{
    sf::RectangleShape newTail(sf::Vector2f(50, 50));
    newTail.setOrigin(25, 25);
    newTail.setPosition(tail.back().getPosition() - sf::Vector2f(55, 0));
    newTail.setFillColor(sf::Color::Green);
    tail.push_back(newTail);
}

void snake::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (const auto& e : tail)
    {
        target.draw(e, states);
    }
}

