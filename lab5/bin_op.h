//
// Created by viro on 2019-11-29.
//

#ifndef LAB5_BIN_OP_H
#define LAB5_BIN_OP_H

#include "monitor.h"

template<typename T>
class bin_op
{
public:
    T operator()(const double& type1, const monitor& monitor)
    {
        return type1 + monitor.getInches();
    }
};


#endif //LAB5_BIN_OP_H
