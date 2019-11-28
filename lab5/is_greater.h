//
// Created by viro on 2019-11-28.
//

#ifndef LAB5_IS_GREATER_H
#define LAB5_IS_GREATER_H


#include "monitor.h"

class is_greater
{
private:
    double value;
public:
    is_greater(double value);

    bool operator()(const monitor& monitor);

};


#endif //LAB5_IS_GREATER_H
