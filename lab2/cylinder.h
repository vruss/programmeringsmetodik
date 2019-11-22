//
// Created by viro on 2019-11-22.
//

#ifndef LAB2_CYLINDER_H
#define LAB2_CYLINDER_H


#include "circle.h"

class cylinder : public circle
{
protected:
    double height;
public:
    cylinder(char* colour, double radius, double height);

    double get_area() const override;
};


#endif //LAB2_CYLINDER_H
