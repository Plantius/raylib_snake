#ifndef SNAKE_H
#define SNAKE_H
#include "/home/niels/projects/game_projects/raylib/src/raylib.h"

enum class direction {UP, DOWN, LEFT, RIGHT, NON};

class snake
{
private:
    Vector2 position;
    float speed;
    direction movementDirection;
    

public:
    snake() : position({0, 0}), speed(0), movementDirection(direction::NON) {};
    snake(const Vector2 position, const float speed, const direction direc) : position(position), 
            speed(speed), movementDirection(direc) {};

    Vector2 getPosition() const {return this->position;};
    
    void setPostition(const Vector2 position) {this->position = position;};
    void setSpeed(const float speed) {this->speed = speed;};
    void setDirection(const direction direc) {this->movementDirection = direc;};
};

#endif