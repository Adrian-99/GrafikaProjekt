#include "Color.h"

Color::Color(GLfloat red, GLfloat green, GLfloat blue)
{
    rgb[0] = red;
    rgb[1] = green;
    rgb[2] = blue;
}

GLfloat Color::Red()
{
    return rgb[0];
}

GLfloat Color::Green()
{
    return rgb[1];
}

GLfloat Color::Blue()
{
    return rgb[2];
}

GLfloat* Color::ToArray()
{
    return rgb;
}
