//
// Created by julia on 2019-11-20.
//

#include "shape.h"

shape::shape(char* colour) : colour(colour)
{
}

char* shape::get_colour() const
{
    return colour;
}


