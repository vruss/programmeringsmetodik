//
// Created by viro on 2019-11-21.
//

#ifndef LAB2_CIRCLE_H
#define LAB2_CIRCLE_H


#include "shape.h"


class circle : public shape
{
protected:
    double radius;

public:
    circle(char* colour, double radius);

    double get_area() const override;

};


#endif //LAB2_CIRCLE_H
