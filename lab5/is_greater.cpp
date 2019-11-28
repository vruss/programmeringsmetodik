//
// Created by viro on 2019-11-28.
//

#include "is_greater.h"

//bool is_greater::operator()(const monitor& lhs, const monitor& rhs)
//{
//    return lhs == rhs;
//}

//bool is_greater::operator()(double greater)
//{
//    return 3 < greater;
//}

is_greater::is_greater(double value)
        : value(value)
{
}


bool is_greater::operator()(const monitor& monitor)
{
    return value > monitor.getInches();
}

