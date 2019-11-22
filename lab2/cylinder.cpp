//
// Created by viro on 2019-11-22.
//
#include <cmath>

#include "cylinder.h"

cylinder::cylinder(char* colour, double radius, double height)
        : circle(colour, radius), height(height)
{
}

double cylinder::get_area() const
{
    return 2 * circle::get_area() + 2 * M_PI * circle::getRadius() * height;
}
