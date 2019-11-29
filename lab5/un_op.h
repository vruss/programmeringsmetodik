//
// Created by viro on 2019-11-29.
//

#ifndef LAB5_UN_OP_H
#define LAB5_UN_OP_H


#include "monitor.h"

template<typename T>
class un_op
{
private:

public:
    T operator()(const T& a)
    {
        return a;
    }

};


#endif //LAB5_UN_OP_H
