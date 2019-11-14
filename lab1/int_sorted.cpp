//
// Created by viro on 2019-11-14.
//

#include "int_sorted.h"


int_sorted::int_sorted(const int* source, size_t size)
        : buffer(source, size)
{
}

size_t int_sorted::size() const
{
    return buffer.size();
}

int* int_sorted::insert(int value)
{
    return nullptr;
}

const int* int_sorted::begin() const
{
    return buffer.begin();
}

const int* int_sorted::end() const
{
    return buffer.end();
}



int_sorted int_sorted::merge(const int_sorted& merge_with) const
{
    size_t sz = merge_with.size() + buffer.size();
    int_buffer new_buffer(sz);
    int_sorted new_sorted(new_buffer.begin(), sz);

    auto new_sorted_it = new_sorted.buffer.begin();
    auto lhs_it = buffer.begin();
    auto rhs_it = merge_with.begin();

    // Iterate until either lhs or rhs is finished
    while (lhs_it != buffer.end() && rhs_it != merge_with.end())
    {
        // Determine what to write to new_buffer
        if (*lhs_it < *rhs_it)
        {
            // Write lhs to new_buffer
            *new_sorted_it = *lhs_it;
            lhs_it++;
            new_sorted_it++;
        }
        else
        {
            // Write rhs to new_buffer
            *new_sorted_it = *rhs_it;
            rhs_it++;
            new_sorted_it++;
        }
    }

    while (lhs_it != buffer.end())
    {
        // Write lhs to new_buffer
        *new_sorted_it = *lhs_it;
        lhs_it++;
        new_sorted_it++;
    }

    while (rhs_it != merge_with.end())
    {
        // Write rhs to new_buffer
        *new_sorted_it = *rhs_it;
        rhs_it++;
        new_sorted_it++;
    }

    return new_sorted;
}



