//
// Laboration: Dynamisk minneshantering, RAII och merge
// Author: Viktor Rosvall
// File name: int_buffer.h - created 2019-11-14 - modified 2019-11-15
// Definition av klass int_sorted som sköter sorting av en int buffer.
//

#ifndef LAB1_INT_SORTED_H
#define LAB1_INT_SORTED_H


#include <cstdlib>
#include "int_buffer.h"

class int_sorted
{
private:
    int_buffer buffer;

    int_sorted(const int_buffer& buffer);

public:

    // Constructors
    int_sorted();

    int_sorted(const int* source, size_t length); // resize constructor

    // Methods
    size_t size() const;

    int* insert(int value); // returns the insertion point.

    const int* begin() const;

    const int* end() const;

    int_sorted merge(const int_sorted& merge_with) const;

    int_sorted sort(const int* begin, const int* end);

    bool isSorted() const;
};


#endif //LAB1_INT_SORTED_H
