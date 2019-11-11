#include <iostream>
#include "int_buffer.h"

void testFunction(int_buffer buf);

int main() {

    int_buffer buff = int_buffer(10);
    testFunction(buff);

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