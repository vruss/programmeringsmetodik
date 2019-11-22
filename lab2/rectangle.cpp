//
// Created by viro on 2019-11-22.
//

#include "rectangle.h"

rectangle::rectangle(char* colour, double width, double height)
        : shape(colour), width(width), height(height)
{
}

double rectangle::get_area() const
{
    return width * height;
}

double rectangle::getWidth() const
{
    return width;
}

double rectangle::getHeight() const
{
    return height;
}
