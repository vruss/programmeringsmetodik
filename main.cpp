#include <iostream>
#include "int_buffer.h"

void testFunction(int_buffer buf);

int main() {

//    int_buffer buff = int_buffer(10); // default constructor
//    testFunction(buff); // copy constructor
//
//    int_buffer buff2 = int_buffer(0); // default constructor
//    buff2 = buff; // copy-assignment constructor
//    testFunction(buff2); // copy constructor
//
//    int_buffer buff3 = std::move(buff); // move constructor
//    testFunction(buff3); // copy constructor
//    testFunction(buff); // copy constructor (empty)
//
//    int_buffer buff4 = int_buffer(0); // move constructor
//    buff4 = std::move(buff2);
//    testFunction(buff4); // copy constructor
//    testFunction(buff2); // copy constructor (empty)

    int_buffer t_buff1 = int_buffer(10);
    int_buffer t_buff2 = t_buff1;
//    int_buffer t_buff3 = std::move(t_buff1);

    testFunction(t_buff1);
    testFunction(t_buff2);
//    testFunction(t_buff3);

    return 0;
}

void testFunction(int_buffer buf) {

    // Set pointer values
    int counter = 0;
    for (int *i = buf.begin(); i != buf.end(); i++) {
        *i = counter;
        counter++;
    }

    // Print address and value
    for (const int *i = buf.begin(); i != buf.end(); i++) {
        std::cout << "Address: " << i << "\t\t" << "Value: " << *i << "\n";
    }
}