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

#define T_RATE 1.5
#define M_SPEED 2
#define GROW_AMOUNT 16

/**
 * @brief   Class that represents a snake
 */
class snake : public sf::Drawable, public sf::Transformable
{
private:
    std::vector<sf::RectangleShape> tail;
    const sf::Vector2f& size;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void moveTailPiece(std::vector<sf::RectangleShape>::iterator tailPiece, const sf::Vector2f& prevPos);

    sf::Vector2f getRotationForTailPiece();

public:

    /**
     * @brief   Constructs a snake object with a position and size
     *
     * @param position  starting position
     * @param size      snake size
     */
    snake(const sf::Vector2f& position, const sf::Vector2f& size);

    /**
     * @brief   Moves the snake forward
     *
     * Calculates the forward vector relative to it's rotation
     *
     * @param speedAmplifier    Speed will be multiplied by this
     */
    void moveForward(float speedAmplifier);

    void grow();

    void rotateRight(float angle);

    /**
     * @brief   Returns position formatted as a string
     *
     * The position string is formatted as "r: " + position
     *
     * @return  position formatted as a string
     */
    std::string getDebugInformation() const;
};


#endif //PROJECT_SNAKE_H
