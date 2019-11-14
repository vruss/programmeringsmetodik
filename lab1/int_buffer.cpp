//
// Laboration: Dynamisk minneshantering, RAII och merge
// Author: Viktor Rosvall
// File name: int_buffer.cpp - created 2019-11-10 - modified 2019-11-10
// Implementation av klass int_buffer som sköter en minnesresurs av typen int.
//

#include <iostream>
#include <algorithm>
#include "int_buffer.h"

// Parameter constructor
int_buffer::int_buffer(size_t size)
        : int_p(new int[size]), length(size)
{
    std::cout << "Parameter constructor!\n";
}

// Resize constructor
int_buffer::int_buffer(const int* source, size_t size)
        : int_p(new int[size]), length(size)
{
    std::cout << "Resize constructor!\n";

    std::copy(source, source + size, int_p);
}

// Copy constructor
int_buffer::int_buffer(const int_buffer& rhs)
        : int_p(new int[rhs.size()]), length(rhs.size())
{
    std::cout << "Copy constructor!\n";
    std::copy(rhs.begin(), rhs.end(), int_p);
}

// Move constructor
int_buffer::int_buffer(int_buffer&& rhs) noexcept
        : int_p(nullptr), length(0)
{
    std::cout << "Move constructor!\n";
    *this = std::move(rhs);
}

// Copy-assignment operator
int_buffer& int_buffer::operator=(const int_buffer& rhs)
{
    std::cout << "Copy-assignment operator!\n";

    if (this != &rhs)
    {
        int_buffer buff(rhs.begin(), rhs.size());
        *this = std::move(buff);
    }
    return *this;
}

// Move-assign operator
int_buffer& int_buffer::operator=(int_buffer&& rhs) noexcept
{
    std::cout << "Move-assignment operator!\n";

    if (this != &rhs)
    {
        length = rhs.length;
        int_p = rhs.int_p;

        rhs.length = 0;
        rhs.int_p = nullptr;
    }
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
    return int_p + size();
}

// Return read-only first pointer
const int* int_buffer::begin() const
{
    return int_p;
}

// Return read-only last pointer
const int* int_buffer::end() const
{
    return &int_p[size()];
}

// Destructor
int_buffer::~int_buffer()
{
    std::cout << "Destructing pointer: " << begin() << std::endl;

    delete[] int_p;
}
