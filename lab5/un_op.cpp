//
// Created by viro on 2019-11-29.
//

#include "un_op.h"

double un_op::operator()(const monitor& monitor)
{
    return monitor.getInches();
}