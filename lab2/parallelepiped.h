//
// Created by viro on 2019-11-22.
//

#ifndef LAB2_PARALLELEPIPED_H
#define LAB2_PARALLELEPIPED_H


#include "rectangle.h"

class parallelepiped : public rectangle
{
private:
    double length;
public:
    parallelepiped(char* colour, double width, double height, double length);

    double get_area() const override;
};


#endif //LAB2_PARALLELEPIPED_H
