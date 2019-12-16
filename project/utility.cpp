//
// Created by Viktor Rosvall (viro1702) on 2019-12-04.
// Student at Mid Sweden University.
//
// Course name: DT047G Programming Methodology
// File name: utility.cpp
//

#include <cmath>
#include <random>
#include "utility.h"

float utility::degToRad(float degrees)
{
    return degrees * (M_PI / 180.0f);
}

float utility::radToDeg(float radians)
{
    return radians * (180.0f / M_PI);
}

sf::Vector2f utility::getRandomPosition(sf::Vector2u bounds)
{
    return sf::Vector2f(getRandomFloat(0, bounds.x), getRandomFloat(0, bounds.y));
}

float utility::getRandomFloat(float min, float max)
{
    std::random_device rd;
    std::uniform_real_distribution<float> dist(min, max);

    return dist(rd);
}
