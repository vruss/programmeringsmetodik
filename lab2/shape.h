//
// Created by julia on 2019-11-20.
//

#ifndef LAB2_SHAPE_H
#define LAB2_SHAPE_H


class shape
{
private:
    char* colour;

public:
    explicit shape(char* colour);

    char* get_colour() const;

    virtual double get_area() const = 0;

};


#endif //LAB2_SHAPE_H
