//
// Created by Christophe on 23/04/2026.
//

#ifndef OPERATORS_VECTOR_H
#define OPERATORS_VECTOR_H
class Vector2
{
public:
    float x;
    float y;
    Vector2(float x, float y);
    Vector2 operator+(const Vector2& p) const;
    Vector2 operator*(const float& m) const;
    bool operator==(const Vector2& b) const;
};


#endif //OPERATORS_VECTOR_H