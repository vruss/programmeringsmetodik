//
// Created by viro on 2019-11-14.
//

#ifndef LAB1_INT_SORTED_H
#define LAB1_INT_SORTED_H


#include <cstdlib>
#include "int_buffer.h"

class int_sorted
{
private:
    int_buffer buffer;

public:

    // Constructors
    int_sorted() = default;
    int_sorted(const int* source, size_t size); // resize constructor

    // Methods
    size_t size() const;

    int* insert(int value); // returns the insertion point.

    const int* begin() const;

    const int* end() const;


    int_sorted merge(const int_sorted& merge_with) const;
};


#endif //LAB1_INT_SORTED_H
