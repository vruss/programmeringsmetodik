//
// Created by Viktor Rosvall (viro1702) on 2019-12-04.
// Student at Mid Sweden University.
//
// Course name: DT047G Programming Methodology
// File name: utility.cpp
//

#include <cmath>
#include "utility.h"

float utility::degToRad(float degrees)
{
    return degrees * (M_PI / 180.0f);
}

float utility::radToDeg(float radians)
{
    return radians * (180.0f / M_PI);
}
