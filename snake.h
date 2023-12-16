#ifndef SNAKE_H
#define SNAKE_H
#include "/home/niels/projects/game_projects/raylib/src/raylib.h"

enum class direction {UP, DOWN, LEFT, RIGHT, NON};

class snake
{
private:
    Vector2 position;
    float speed;
    

public:
    snake() : position({0, 0}), speed(0) {};
    snake(const Vector2 position, const float speed) : position(position), 
            speed(speed) {};

    Vector2 getPosition() const {return this->position;};
    
    void setPosition(const Vector2 position);
    void setSpeed(const float speed) {this->speed = speed;};
};

#endif