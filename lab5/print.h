//
// Created by viro on 2019-11-28.
//

#ifndef LAB5_PRINT_H
#define LAB5_PRINT_H


#include <iostream>
#include "monitor.h"

class print
{
public:
    void operator()(const monitor& monitor);

    void operator()(double value);
};


#endif //LAB5_PRINT_H
