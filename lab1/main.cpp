#include <iostream>
#include <random>

#include "int_buffer.h"
#include "int_sorted.h"

void testFunction(int_buffer buf);

void makeRandomBuffer(int_buffer& buffer);

int_sorted sort(const int* begin, const int* end);

void print(const int_buffer& buffer);

void print(const int_sorted& buffer);

int main()
{

//    std::cout << "\nbuff1\n";
//    int_buffer buff1 = int_buffer(10); // parameter constructor
//    testFunction(buff1); // copy constructor
//
//    std::cout << "\nbuff2\n";
//    int_buffer buff2 = int_buffer(0); // parameter constructor
//    buff2 = buff1; // copy-assignment constructor
//    testFunction(buff2); // copy constructor
//
//    std::cout << "\nbuff3\n";
//    int_buffer buff3 = std::move(buff1); // move constructor
//    testFunction(buff3); // copy constructor
//    testFunction(buff1); // copy constructor (empty)
//
//    std::cout << "\nbuff4\n";
//    int_buffer buff4 = int_buffer(0); // parameter constructor
//    buff4 = std::move(buff2); // move-assignment operator
//    testFunction(buff4); // copy constructor
//    testFunction(buff2); // copy constructor (empty)
//
    std::cout << "\nbuff5\n";
    int_buffer buff5(2); // resize constructor
    int_buffer buff6(3); // resize constructor

    makeRandomBuffer(buff5);
    makeRandomBuffer(buff6);
    print(buff5);
    print(buff6);

    int_sorted sorted1(buff5.begin(), buff5.size());
    int_sorted sorted2(buff6.begin(), buff6.size());

    int_sorted sorted3 = sorted1.merge(sorted2);
    print(sorted3);
    return 0;
}

int_sorted sort(const int* begin, const int* end)
{
    if (begin == end)
        return int_sorted();
    if (begin == end - 1)
        return
                int_sorted(*begin, 1);
    std::ptrdiff_t half = (end - begin) / 2; // pointer diff type
    const int* mid = begin + half;
    return sort(begin, mid).merge(sort(
            mid, end));
}

void makeRandomBuffer(int_buffer& buffer)
{
    std::random_device generator;
    std::uniform_int_distribution<int> rnd(0, 100);

    // Set pointer values
    for (int& element : buffer)
    {
        element = rnd(generator);
    }

}

void print(const int_buffer& buffer)
{
    // Print address and value
    for (const int* i = buffer.begin(); i != buffer.end(); i++)
    {
        std::cout << "Address: " << i << "\t\t" << "Value: " << *i << "\n";
    }
}

void print(const int_sorted& buffer)
{
    // Print address and value
    for (const int* i = buffer.begin(); i != buffer.end(); i++)
    {
        std::cout << "Address: " << i << "\t\t" << "Value: " << *i << "\n";
    }
}

void testFunction(int_buffer buf)
{

    // Set pointer values
    int counter = 1;
    for (int* i = buf.begin(); i != buf.end(); i++)
    {
        *i = counter;
        counter++;
    }

    // Print address and value
    for (const int* i = buf.begin(); i != buf.end(); i++)
    {
        std::cout << "Address: " << i << "\t\t" << "Value: " << *i << "\n";
    }
}