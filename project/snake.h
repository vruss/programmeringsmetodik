//
// Created by Viktor Rosvall (viro1702) on 2019-12-03.
// Student at Mid Sweden University.
//
// Course name: DT047G Programming Methodology
// File name: snake.h
//

#ifndef PROJECT_SNAKE_H
#define PROJECT_SNAKE_H

#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

// Default values for the snake
#define T_RATE 1.5
#define M_SPEED 2
#define GROW_AMOUNT 16

/**
 * @brief   Class that represents a snake
 *
 * @def     defines default values for turn rate (T_RATE), movement speed (M_SPEED) and grow amount (GROW_AMOUNT)
 */
class snake : public sf::Drawable, public sf::Transformable
{
private:
    std::vector<sf::RectangleShape> tail;
    const sf::Vector2f& size;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void moveTailPiece(std::vector<sf::RectangleShape>::iterator tailPiece, const sf::Vector2f& prevPos);

    sf::Vector2f CalculateDirectionForHead(float speedAmplifier);

    float calculateAngleToTarget(const sf::Vector2f& currentPos, const sf::Vector2f& target);

public:

    /**
     * @brief   Constructs a snake object with a starting position and size
     *
     * @param position  starting position
     * @param size      snake size
     */
    snake(const sf::Vector2f& position, const sf::Vector2f& size);

    /**
     * @brief   Moves the snake forward
     *
     * Calculates a forward vector relative to it's rotation.
     * All tailpieces will move to the previous tailpiece location.
     *
     * @param speedAmplifier    Speed will be multiplied by this
     */
    void moveForward(float speedAmplifier);

    /**
     * @brief   Grows the snake by a fixed amount
     */
    void grow();

    /**
     * @brief   Rotates the snake right
     *
     * The snake will rotate left if the angle parameter is negative.
     *
     * @param angle
     */
    void rotateRight(float angle);

    /**
     * @brief   Returns debugging information about the snake
     *
     * Each line represents a snake piece.
     *
     * @return  formatted string containing x, y positions and it's rotation in degrees.
     */
    std::string getDebugInformation() const;
};


#endif //PROJECT_SNAKE_H
