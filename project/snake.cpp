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
#include <memory>

#include "snake.h"
#include "utility.h"
#include "libs/rectangularBoundaryCollision.hpp"

snake::snake(const sf::Vector2f& position, const sf::Vector2f& size, sf::Keyboard::Key leftKey,
             sf::Keyboard::Key rightKey)
        : tail(), size(size), leftKey(leftKey), rightKey(rightKey), head(size)
{
    // Make snake head
    head.setPosition(position);
    head.setOrigin(size.x / 2, size.y / 2);
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
        newTail.setFillColor(sf::Color::Cyan);
        tail.push_back(newTail);
    }
}

void snake::handleEvents(sf::Event& event)
{
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::G)
        {
            grow();
        }
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


bool snake::isColliding(std::vector<std::shared_ptr<snake>>& snakes)
{
    bool hasCollided = false;
    for (const auto& _snake: snakes)
    {
        // Skip checking collision against self
        if (_snake.get() == this)
        {
            continue;
        }

        // Look for a collision between this snake head and other snake body parts
        for (auto& otherTail : _snake->getTail())
        {
            if (collision::areColliding(head, otherTail))
            {
                hasCollided = true;
                head.setFillColor(sf::Color::Yellow);
                break; // TODO: punish this snake
            }
        }
    }
    return hasCollided;
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








