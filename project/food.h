//
// Created by Viktor Rosvall (viro1702) on 2019-12-11.
// Student at Mid Sweden University.
//
// Course name: DT047G Programming Methodology
// File name: food.h
//

#ifndef PROJECT_FOOD_H
#define PROJECT_FOOD_H

#include <SFML/Graphics.hpp>

/**
 * @brief   Class that represents a piece of food
 */
class food : public sf::Drawable
{
private:
    sf::RectangleShape foodShape;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    /**
     * @brief   Constructs a piece of food at a starting location with a size
     *
     * @param size      food size
     * @param position  starting location
     */
    food(const sf::Vector2f& size, const sf::Vector2f& position);

    /**
     * @return  const reference to food piece container
     */
    const sf::RectangleShape& getFoodShape() const;

    /**
     * @return  reference to food piece container
     */
    sf::RectangleShape& getFoodShape();
};


#endif //PROJECT_FOOD_H
