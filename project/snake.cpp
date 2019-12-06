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


void snake::moveForward(float speedAmplifier)
{
    // Move head forward
    sf::Vector2f prevPos = tail.front().getPosition();
    sf::Vector2f direction;
    float rotation = utility::degToRad(tail.front().getRotation());
    direction.x = std::cos(rotation) * speedAmplifier;
    direction.y = std::sin(rotation) * speedAmplifier;
    tail.front().move(direction);

    // Move body forward
    if (tail.size() < 2)
        return;
    for (auto tailPiece = tail.begin() + 1; tailPiece != tail.end(); tailPiece++)
    {
        if(tailPiece->getGlobalBounds().contains(tail.front().getPosition())) {
            std::cout << "intersect\n";

        }
        sf::Vector2f targetVector = prevPos - tailPiece->getPosition();
        float angleToTarget = atan2f(targetVector.y, targetVector.x);
        direction.x = std::cos(angleToTarget) * speedAmplifier;
        direction.y = std::sin(angleToTarget) * speedAmplifier;

        //TODO: Make snake body part move slower so it doesn't overlap with head
        tailPiece->move(direction);
        tailPiece->setRotation(utility::radToDeg(angleToTarget));

        prevPos = tailPiece->getPosition();
    }
}

void snake::grow()
{
    sf::RectangleShape newTail(sf::Vector2f(50, 50));
    newTail.setOrigin(50 / 2, 50 / 2);
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

void snake::rotateRight(float angle)
{
    tail.front().rotate(angle);
}


std::string snake::getStringPosition() const
{
    std::string text;

    for (const auto& e : tail)
    {
        std::string xPos = std::to_string(e.getPosition().x);
        std::string yPos = std::to_string(e.getPosition().y);

        text.append("x: " + xPos + " y: " + yPos + "\n");
    }
    return text;
}

std::string snake::getStringRotation() const
{
    std::string rotation = std::to_string(sf::Transformable::getRotation());
    return "r: " + rotation;
}