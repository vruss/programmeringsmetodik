//
// Created by viro on 2019-11-22.
//

#include <cmath>
#include "rounded_rectangle.h"
#include "circle.h"

rounded_rectangle::rounded_rectangle(char* colour, double width, double height, double radius)
        : rectangle(colour, width, height), radius(radius)
{
}

double rounded_rectangle::get_area() const
{
    circle corners(get_colour(), radius);
//    return rectangle::get_area() - 4 * corners.get_area();
    return height * width - (radius * radius) * (4 - M_PI);
}
