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
#include "food.h"

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
    sf::Keyboard::Key leftKey;
    sf::Keyboard::Key rightKey;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void moveTailPiece(std::vector<sf::RectangleShape>::iterator tailPiece, const sf::Vector2f& prevPos);

    sf::Vector2f CalculateDirectionForHead(float speedAmplifier);

    static float calculateAngleToTarget(const sf::Vector2f& currentPos, const sf::Vector2f& target);

public:

    /**
     * @brief   Constructs a snake object with a starting position and size
     *
     * @param position  starting position
     * @param size      snake size
     */
    snake(const sf::Vector2f& position, const sf::Vector2f& size, sf::Keyboard::Key leftKey,
          sf::Keyboard::Key rightKey);

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
     * @brief   Handles user events
     *
     * @param event     type of event
     */
    void handleEvents(sf::Event& event);

    /**
     * @brief   Handles user input for turning and boosting
     *
     * @param leftKey   key pressed for left turn
     * @param rightKey  key pressed for right turn
     */
    void handleInput();

    /**
     * @brief   Checks if snake head is colliding with other snakes' tail
     *
     * This collision check takes snake rotation into account.
     *
     * @param snakes    all snakes this snake can collide with
     * @return          true if a collision has occurred
     */
    bool isColliding(const std::vector<std::shared_ptr<snake>>& snakes);

    /**
     * @brief   Checks if snake head is colliding with food
     *
     * This collision check takes snake rotation into account.
     * Will return a pointer to the collided food piece,
     * or nullptr if no collision detected.
     *
     * @param foodBowl  all food pieces this snake can collide with
     * @return          the a pointer to the collided food piece
     */
    std::shared_ptr<food> isColliding(std::vector<std::shared_ptr<food>>& foodBowl);

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
