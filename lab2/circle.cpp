//
// Created by viro on 2019-11-21.
//
#include <cmath>

#include "circle.h"

circle::circle(char* colour, double radius)
: shape(colour), radius(radius)
{
}

double circle::get_area() const
{
    return M_PI * (radius * radius);
}
