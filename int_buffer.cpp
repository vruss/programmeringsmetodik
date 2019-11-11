//
// Laboration: Dynamisk minneshantering, RAII och merge
// Author: Viktor Rosvall
// File name: int_buffer.cpp - created 2019-11-10 - modified 2019-11-10
// Implementation av klass int_buffer som sköter en minnesresurs av typen int.
//

#include <iostream>
#include "int_buffer.h"

// Default constructor
int_buffer::int_buffer(size_t size) {
    std::cout << "Default constructor!\n";

    this->int_p = new int[size];
    this->length = size;
}

// Resize constructor
int_buffer::int_buffer(const int *source, size_t size) {
    std::cout << "Resize constructor!\n";

}

// Copy constructor
int_buffer::int_buffer(const int_buffer &rhs) {
    std::cout << "Copy constructor!\n";

    this->int_p = new int;
    this->length = rhs.length;
    *(this->int_p) = *(rhs.int_p);
}

// Move constructor
int_buffer::int_buffer(int_buffer &&rhs) {
    std::cout << "Move constructor!\n";

}

// Copy-assignment operator
int_buffer &int_buffer::operator=(const int_buffer &rhs) {
    std::cout << "Copy-assignment operator!\n";

    if (this != &rhs) {

    }
}

// Move-assign operator
int_buffer &int_buffer::operator=(int_buffer &&rhs) {
    std::cout << "Move-assignment operator!\n";

//    return <#initializer#>;
}

// Return buffer size
size_t int_buffer::size() const {
    return this->length;
}

// Return first pointer
int *int_buffer::begin() {
    return this->int_p;
}

// Return last pointer
int *int_buffer::end() {
    return &this->int_p[size()];
}

// Return read-only first pointer
const int *int_buffer::begin() const {
    return this->int_p;
}

// Return read-only last pointer
const int *int_buffer::end() const {
    return &this->int_p[size()];
}

// Destructor
int_buffer::~int_buffer() {
    std::cout << "Destructor!\n";

    delete[] this->int_p;
    this->int_p = nullptr;
}
