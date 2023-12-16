#include "snake.h"

void snake::setPosition(const Vector2 position) 
{
    this->position.x += position.x;
    this->position.y += position.y;
}// setPosition