//
// Created by Christophe on 23/04/2026.
//

#include "vector.h"

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector2 Vector2::operator+(const Vector2 &p) const
{
    return Vector2(this->x+p.x,this->y+p.y);
}

Vector2 Vector2::operator*(const float &m) const
{
    return Vector2(this->x*m, this->y*m);
}

bool Vector2::operator==(const Vector2& b) const
{
    return (this->x == b.x && this->y == b.y);
}

