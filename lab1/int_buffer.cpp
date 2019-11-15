//
// Laboration: Dynamisk minneshantering, RAII och merge
// Author: Viktor Rosvall
// File name: int_buffer.cpp - created 2019-11-10 - modified 2019-11-15
// Implementation av klass int_buffer som sköter en minnesresurs av typen int.
//

#include <iostream>
#include <algorithm>
#include "int_buffer.h"

// Parameter constructor
int_buffer::int_buffer(size_t size)
        : int_p(new int[size]), length(size)
{
}

// Resize constructor
int_buffer::int_buffer(const int* source, size_t size)
        : int_buffer(size)
{
    std::copy_n(source, size, int_p);
}

// Copy constructor
int_buffer::int_buffer(const int_buffer& rhs)
        : int_buffer(rhs.begin(), rhs.length)
{
}

// Move constructor
int_buffer::int_buffer(int_buffer&& rhs) noexcept
        : int_buffer(nullptr, 0)
{
    swap(rhs); // swap rhs with null object
}

// Copy-assignment operator
int_buffer& int_buffer::operator=(const int_buffer& rhs)
{
    int_buffer tmp(rhs);
    swap(tmp);
    return *this;
}

// Move-assign operator
int_buffer& int_buffer::operator=(int_buffer&& rhs) noexcept
{
    swap(rhs);
    return *this;
}

// Return buffer size
size_t int_buffer::size() const
{
    return length;
}

// Return first pointer
int* int_buffer::begin()
{
    return int_p;
}

// Return last pointer
int* int_buffer::end()
{
    return int_p + length;
}

// Return read-only first pointer
const int* int_buffer::begin() const
{
    return int_p;
}

// Return read-only last pointer
const int* int_buffer::end() const
{
    return &int_p[length];
}

// Destructor
int_buffer::~int_buffer()
{
    delete[] int_p;
}

void int_buffer::swap(int_buffer& rhs)
{
    std::swap(length, rhs.length);
    std::swap(int_p, rhs.int_p);
}

int& int_buffer::operator[](size_t index)
{
    return int_p[index];
}

const int& int_buffer::operator[](size_t index) const
{
    return int_p[index];
}
