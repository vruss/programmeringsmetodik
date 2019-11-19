//
// Laboration: Dynamisk minneshantering, RAII och merge
// Author: Viktor Rosvall
// File name: int_buffer.h - created 2019-11-14 - modified 2019-11-19
// Implementation av klass int_sorted som sköter sorting av en int buffer.
//

#include <algorithm>
#include "int_sorted.h"

int_sorted::int_sorted()
        : buffer(nullptr, 0)
{
}

int_sorted::int_sorted(const int* source, size_t length)
        : buffer(source, length)
{
    if (size() != 1)
    {
        *this = sort(source, source + length);
    }
}

int_sorted::int_sorted(const int_buffer& buffer)
        : buffer(buffer)
{

}

size_t int_sorted::size() const
{
    return buffer.size();
}

int* int_sorted::insert(int value)
{
    *this = merge(int_sorted(&value, 1));
    return std::find(buffer.begin(), buffer.end(), value);
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
    int_buffer tmpBuffer(sz);

    auto buffer_it = tmpBuffer.begin();
    auto lhs_it = buffer.begin();
    auto rhs_it = merge_with.begin();

    // Iterate until either lhs or rhs is finished
    while (lhs_it != buffer.end() && rhs_it != merge_with.end())
    {
        // Determine what to write to tmpBuffer
        if (*lhs_it < *rhs_it)
        {
            // Write lhs to tmpBuffer
            *buffer_it = *lhs_it++;
            buffer_it++;
        }
        else
        {
            // Write rhs to tmpBuffer
            *buffer_it = *rhs_it++;
            buffer_it++;
        }
    }

    while (lhs_it != buffer.end())
    {
        // Write lhs to tmpBuffer
        *buffer_it = *lhs_it++;
        buffer_it++;
    }

    while (rhs_it != merge_with.end())
    {
        // Write rhs to tmpBuffer
        *buffer_it = *rhs_it++;
        buffer_it++;
    }

    // Create a new sorted buffer
    return int_sorted(tmpBuffer);
}

int_sorted int_sorted::sort(const int* begin, const int* end)
{
    if (begin == end)
        return int_sorted();
    if (begin == end - 1)
        return int_sorted(begin, 1);

    std::ptrdiff_t half = (end - begin) / 2; // pointer diff type
    const int* mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));
}

bool int_sorted::isSorted() const
{
    auto it = begin();

    int a = *it++;
    while (it != end())
    {
        int b = *it++;

        if (a > b)
        {
            return false;
        }
        a = b;
    }
    return true;
}


