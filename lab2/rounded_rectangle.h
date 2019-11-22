//
// Created by viro on 2019-11-22.
//

#ifndef LAB2_ROUNDED_RECTANGLE_H
#define LAB2_ROUNDED_RECTANGLE_H


#include "rectangle.h"

class rounded_rectangle : public rectangle
{
protected:
    double radius;
public:
    rounded_rectangle(char* colour, double width, double height, double radius);

    double get_area() const override;
};


#endif //LAB2_ROUNDED_RECTANGLE_H
