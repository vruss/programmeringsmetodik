//
// Created by Viktor Rosvall (viro1702) on 2019-12-03.
// Student at Mid Sweden University.
//
// Course name: DT047G Programming Methodology
// File name: snake.cpp
//

#include <cmath>
#include <iostream>
#include <memory>

#include "snake.h"
#include "utility.h"
#include "libs/rectangularBoundaryCollision.hpp"

snake::snake(const sf::Vector2f& position, const sf::Vector2f& size, sf::Keyboard::Key leftKey,
             sf::Keyboard::Key rightKey, const sf::Color& color)
        : tail(), size(size), leftKey(leftKey), rightKey(rightKey), head(size), color(color)
{
    // Make snake head
    head.setPosition(position);
    head.setOrigin(size.x / 2, size.y / 2);
    head.setRotation(utility::getRandomFloat(0, 360));
    head.setFillColor(sf::Color::Red);

    // Grow snake body
    grow();
}

void
snake::moveTailPiece(std::vector<sf::RectangleShape>::iterator tailPiece, const sf::Vector2f& prevPos)
{
    float angleToTarget = calculateAngleToTarget(tailPiece->getPosition(), prevPos);

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
    sf::Vector2f direction = CalculateDirectionForHead(speedAmplifier);
    sf::Vector2f prevHeadPos = head.getPosition();

    // Move snake head forward
    head.move(direction);

    // Move snake body
    moveTailPiece(tail.begin(), prevHeadPos);
}

void snake::grow()
{
    for (int i = 0; i < GROW_AMOUNT; i++)
    {
        sf::RectangleShape newTail(size);
        newTail.setOrigin(size.x / 2, size.y / 2);
        newTail.setPosition((tail.empty()) ? head.getPosition() : tail.back().getPosition());
        newTail.setRotation((tail.empty()) ? head.getRotation() : tail.back().getRotation());
        newTail.setFillColor(color);
        tail.emplace_back(newTail);
    }
}

void snake::handleInput()
{
    if (sf::Keyboard::isKeyPressed(leftKey))
    {
        rotateRight(-T_RATE);
    }
    if (sf::Keyboard::isKeyPressed(rightKey))
    {
        rotateRight(T_RATE);
    }
}

bool snake::isColliding(const sf::RectangleShape& other)
{
    return collision::areColliding(head, other);
}

void snake::reset(const sf::Vector2f& newPosition)
{
    // Move head to random position
    head.setPosition(newPosition);
    head.setRotation(utility::getRandomFloat(0, 360));

    // Reset tail length
    tail.erase(tail.begin(), tail.end());
    grow();
}

sf::Vector2f snake::CalculateDirectionForHead(float speedAmplifier)
{
    sf::Vector2f direction;
    float rotation = utility::degToRad(head.getRotation());
    direction.x = std::cos(rotation) * speedAmplifier;
    direction.y = std::sin(rotation) * speedAmplifier;
    return direction;
}

float snake::calculateAngleToTarget(const sf::Vector2f& currentPos, const sf::Vector2f& target)
{
    sf::Vector2f targetVector = target - currentPos;
    float angleToTarget = atan2f(targetVector.y, targetVector.x);
    return angleToTarget;
}


void snake::rotateRight(float angle)
{
    head.rotate(angle);
}

void snake::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // Draws head. Will be drawn under tail if places before tail draw
    target.draw(head, states);
    for (const auto& tailPiece : tail)
    {
        target.draw(tailPiece, states);
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
        text.append("x: " + xPos + " y: " + yPos + " r: " + rotation + "\n");
    }
    return text;
}

const std::vector<sf::RectangleShape>& snake::getTail() const
{
    return tail;
}

