//
// Created by Viktor Rosvall (viro1702) on 2019-12-16.
// Student at Mid Sweden University.
// 
// Course name: DT047G Programming Methodology
// File name: wallBuilder.cpp 
//

#include "wallBuilder.h"

wallBuilder::wallBuilder(const sf::Vector2f& wallSize, const sf::Vector2u& roomSize)
        : wallSize(wallSize), roomSize(roomSize)
{
}

sf::RectangleShape wallBuilder::buildLeftWall()
{
    return sf::RectangleShape(sf::Vector2f(wallSize.x, roomSize.y));
}

sf::RectangleShape wallBuilder::buildRightWall()
{
    auto wall = sf::RectangleShape(sf::Vector2f(wallSize.x, roomSize.y));
    wall.setPosition(sf::Vector2f(roomSize.x - wallSize.x, 0));
    return wall;
}

sf::RectangleShape wallBuilder::buildTopWall()
{
    return sf::RectangleShape(sf::Vector2f(roomSize.x, wallSize.y));
}

sf::RectangleShape wallBuilder::buildDownWall()
{
    auto wall = sf::RectangleShape(sf::Vector2f(roomSize.x, wallSize.y));
    wall.setPosition(sf::Vector2f(0, roomSize.y - wallSize.y));
    return wall;
}
