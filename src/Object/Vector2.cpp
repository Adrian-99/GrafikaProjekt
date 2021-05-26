#include "Vector2.h"

Vector2::Vector2(GLfloat x, GLfloat y)
{
    position[0] = x;
    position[1] = y;
}

GLfloat Vector2::X()
{
    return position[0];
}

GLfloat Vector2::Y()
{
    return position[1];
}

GLfloat Vector2::X(GLfloat newX)
{
    position[0] = newX;
    return newX;
}

GLfloat Vector2::Y(GLfloat newY)
{
    position[1] = newY;
    return newY;
}

GLfloat* Vector2::ToArray()
{
    return position;
}

Vector2 Vector2::operator+(const Vector2& v)
{
    return Vector2(this->position[0] + v.position[0], this->position[1] + v.position[1]);
}

Vector2 Vector2::operator-(const Vector2& v)
{
    return Vector2(this->position[0] - v.position[0], this->position[1] - v.position[1]);
}

Vector2 Vector2::operator*(const GLfloat& num)
{
    return Vector2(this->position[0] * num, this->position[1] * num);
}

Vector2 Vector2::operator/(const GLfloat& num)
{
    return Vector2(this->position[0] / num, this->position[1] / num);
}

Vector2& Vector2::operator+=(const Vector2& v)
{
    this->position[0] += v.position[0];
    this->position[1] += v.position[1];
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& v)
{
    this->position[0] -= v.position[0];
    this->position[1] -= v.position[1];
    return *this;
}

Vector2& Vector2::operator*=(const GLfloat& num)
{
    this->position[0] *= num;
    this->position[1] *= num;
    return *this;
}

Vector2& Vector2::operator/=(const GLfloat& num)
{
    this->position[0] /= num;
    this->position[1] /= num;
    return *this;
}

bool Vector2::operator!=(const Vector2& v)
{
    return this->position[0] != v.position[0] || this->position[1] != v.position[1];
}
