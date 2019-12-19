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
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

// Default values for the snake
#define T_RATE 1.75
#define M_SPEED 2
#define GROW_AMOUNT 16

/**
 * @brief   Class that represents a snake
 */
class snake : public sf::Drawable
{
private:
    sf::RectangleShape head;
    std::vector<sf::RectangleShape> tail;
    const sf::Vector2f& size;
    const sf::Color color;
    const sf::Keyboard::Key leftKey;
    const sf::Keyboard::Key rightKey;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void moveTailPiece(std::vector<sf::RectangleShape>::iterator tailPiece, const sf::Vector2f& prevPos);

    sf::Vector2f CalculateDirectionForHead(float speedAmplifier);

    static float calculateAngleToTarget(const sf::Vector2f& currentPos, const sf::Vector2f& target);

public:

    /**
     * @brief   Constructs a snake object with starting parameters
     *
     * Constructs a snake with keyboard shortcuts associated.
     * It also has a size and color.
     *
     * @param position  starting position
     * @param size      snake size
     * @param leftKey   keyboard shortcut for left turn
     * @param rightKey  keyboard shortcut for right turn
     * @param color     snake color
     */
    snake(const sf::Vector2f& position, const sf::Vector2f& size, sf::Keyboard::Key leftKey,
          sf::Keyboard::Key rightKey, const sf::Color& color);

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
     * @brief   Handles user input for turning and boosting
     */
    void handleInput();

    /**
     * @brief   Check if snake is colliding with other rectangle shape
     *
     * @param other other shape to check collision with
     * @return      true if collision happened, false if not not
     */
    bool isColliding(const sf::RectangleShape& other);

    /**
     * @brief   Resets the snake with a new position and small size
     *
     * @param newPosition   the new spawn position
     */
    void reset(const sf::Vector2f& newPosition);

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

    /**
     * @return  snake tail
     */
    const std::vector<sf::RectangleShape>& getTail() const;
};


#endif //PROJECT_SNAKE_H
