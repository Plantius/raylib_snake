#ifndef OBJECT_H
#define OBJECT_H

#include "raylib.h"

enum class objectType {COIN, OBSTACLE, NON};

class object
{
public:
    object() : size({0, 0}), type(objectType::NON) {};

protected:
    Vector2 position;
    Vector2 size;
    objectType type;
    
};

class coin : public object{
    public:
        coin() {this->position = {0, 0}; this->size = {5, 5}; this->type = objectType::COIN;};
        coin(const Vector2 position) {this->position = position;};

        Vector2 getPosition() const {return this->position;};
        Vector2 getSize() const {return this->size;};

        void setPosition(const Vector2 position);
};



#endif