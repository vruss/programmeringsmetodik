//
// Created by viro on 2019-11-22.
//

#ifndef LAB2_RECTANGLE_H
#define LAB2_RECTANGLE_H


#include "shape.h"

class rectangle : public shape
{
private:
    double width;
    double height;
public:
    rectangle(char* colour, double width, double height);

    double get_area() const override;

    double getWidth() const;

    double getHeight() const;
};


#endif //LAB2_RECTANGLE_H
