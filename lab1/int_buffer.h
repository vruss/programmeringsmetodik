//
// Laboration: Dynamisk minneshantering, RAII och merge
// Author: Viktor Rosvall
// File name: int_buffer.h - created 2019-11-10 - modified 2019-11-15
// Definition av klass int_buffer som sköter en minnesresurs av typen int.
//

#ifndef LAB1_INT_BUFFER_H
#define LAB1_INT_BUFFER_H


#include <cstdlib>

class int_buffer
{
private:
    int* int_p;
    size_t length;

    void swap(int_buffer& rhs);

public :

    // Constructors
    int_buffer() = delete; // default constructor
    explicit int_buffer(size_t size); // parameter constructor
    int_buffer(const int* source, size_t size); // resize constructor

    int_buffer(const int_buffer& rhs); // copy constructor
    int_buffer(int_buffer&& rhs) noexcept; // move constructor

    // Operator overloads
    int_buffer& operator=(const int_buffer& rhs); // copy-assignment operator
    int_buffer& operator=(int_buffer&& rhs) noexcept; // move-assign operator

    int& operator[](size_t index);

    const int& operator[](size_t index) const;

    // Methods
    size_t size() const;

    int* begin();

    int* end();

    const int* begin() const;

    const int* end() const;

    ~ int_buffer(); // destructor
};


#endif //LAB1_INT_BUFFER_H
