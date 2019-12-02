//
// Created by viro on 2019-11-28.
//

#include "print.h"


void print::operator()(const monitor& monitor)
{
    std::cout << monitor << std::endl;
}

void print::operator()(double value)
{
    std::cout << value << std::endl;

}
