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

GLfloat* Vector2::ToArray()
{
    return position;
}
