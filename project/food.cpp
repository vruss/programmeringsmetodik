//
// Created by Viktor Rosvall (viro1702) on 2019-12-11.
// Student at Mid Sweden University.
//
// Course name: DT047G Programming Methodology
// File name: food.cpp
//


#include "food.h"


food::food(const sf::Vector2f& size, const sf::Vector2f& position)
        : foodShape(size)
{
    foodShape.setPosition(position);
    foodShape.setFillColor(sf::Color::Red);
}

void food::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(foodShape, states);
}

const sf::RectangleShape& food::getFoodShape() const
{
    return foodShape;
}

sf::RectangleShape& food::getFoodShape()
{
    return foodShape;
}
