//
// Created by viro on 2019-11-22.
//

#include <cmath>
#include "rounded_rectangle.h"

rounded_rectangle::rounded_rectangle(char* colour, double width, double height, double radius)
        : rectangle(colour, width, height), radius(radius)
{
}

double rounded_rectangle::get_area() const
{
    return height * width - (radius * radius) * (4 - M_PI);
}
