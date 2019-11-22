//
// Created by viro on 2019-11-22.
//

#include "parallelepiped.h"

parallelepiped::parallelepiped(char* colour, double width, double height, double length)
        : rectangle(colour, width, height), length(length)
{
}

double parallelepiped::get_area() const
{
    return (rectangle::getWidth() * 2 + rectangle::getHeight() * 2) * length
           + 2 * rectangle::get_area();
}
