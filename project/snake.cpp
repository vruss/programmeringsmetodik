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
        : tail(), size(size)
{
    // Make snake head
    sf::RectangleShape rect(size);
    rect.setPosition(position);
    rect.setOrigin(size.x / 2, size.y / 2);
    rect.setFillColor(sf::Color::Red);
    tail.push_back(rect);

    // Grow snake body
    grow();
}


void
snake::moveTailPiece(std::vector<sf::RectangleShape>::iterator tailPiece, const sf::Vector2f& prevPos)
{
    sf::Vector2f direction;
    sf::Vector2f targetVector = prevPos - tailPiece->getPosition();
    float angleToTarget = atan2f(targetVector.y, targetVector.x);
    direction.x = std::cos(angleToTarget);
    direction.y = std::sin(angleToTarget);

    // Save this tailpiece position for next tailpiece
    sf::Vector2f thisPrevPos = tailPiece->getPosition();

    // Move tailpiece
    tailPiece->setPosition(prevPos);

    // Stop tailpiece rotation if the angle is 0
    // This is done to prevent a visual artifact
    if (angleToTarget != 0)
    {
        tailPiece->setRotation(utility::radToDeg(angleToTarget));
    }

    // Move next tailpiece if it's not the last
    if (++tailPiece != tail.end())
    {
        moveTailPiece(tailPiece, thisPrevPos);
    }
}

void snake::moveForward(float speedAmplifier)
{
    // Move snake head forward
    sf::Vector2f prevHeadPos = tail.front().getPosition();
    sf::Vector2f direction;
    float rotation = utility::degToRad(tail.front().getRotation());
    direction.x = std::cos(rotation) * speedAmplifier;
    direction.y = std::sin(rotation) * speedAmplifier;
    tail.front().move(direction);

    // Move snake body
    auto tailPiece = tail.begin();
    moveTailPiece(++tailPiece, prevHeadPos);
}

void snake::grow()
{
    for (int i = 0; i < GROW_AMOUNT; i++)
    {
        sf::RectangleShape newTail(size);
        newTail.setOrigin(size.x / 2, size.y / 2);
        newTail.setPosition(tail.back().getPosition());
        newTail.setRotation(tail.back().getRotation());
        newTail.setFillColor(sf::Color::Green);
        tail.push_back(newTail);
    }
}

void snake::rotateRight(float angle)
{
    tail.front().rotate(angle);
}

void snake::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (const auto& e : tail)
    {
        target.draw(e, states);
    }
}

std::string snake::getDebugInformation() const
{
    std::string text;

    std::string numberOfPieces = std::to_string(tail.size());
    text.append("Snake length: " + numberOfPieces + "\n");

    for (const auto& e : tail)
    {
        std::string xPos = std::to_string(e.getPosition().x);
        std::string yPos = std::to_string(e.getPosition().y);
        std::string rotation = std::to_string(e.getRotation());
        std::cout << rotation << "\n";

        text.append("x: " + xPos + " y: " + yPos + " r: " + rotation + "\n");
    }
    return text;
}

