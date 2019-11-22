//
// Created by viro on 2019-11-22.
//

#ifndef LAB2_RECTANGLE_H
#define LAB2_RECTANGLE_H


#include "shape.h"

class rectangle : public shape
{
protected:
    double width;
    double height;
public:
    rectangle(char* colour, double width, double height);

    double get_area() const override;
};


#endif //LAB2_RECTANGLE_H
