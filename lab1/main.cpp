#include <iostream>
#include <random>

#include "int_buffer.h"
#include "int_sorted.h"

void testFunction(int_buffer buf);

int_buffer generateRandomNumbers(int n);

int_buffer generateAscendingNumbers(int n);

int_sorted sort(const int* begin, const int* end);

void print(const int_buffer& buffer);

void print(const int_sorted& buffer);

int main()
{
    int int_list1[5] = {2, 3, 1, 6, 5};
    int int_list2[2] = {3, 2};

    int_buffer buff1(10); // parameter constructor

    int_buffer buff2 = buff1; // copy-assignment constructor

    int_buffer buff3(int_list1, 5); // resize constructor

    buff1 = buff3; // copy-assignment operator

    int_buffer buff4 = int_buffer(0); // parameter constructor
    buff4 = std::move(buff2); // move-assignment operator

    int_buffer buff5 = std::move(buff1); // move constructor


    // Sorting phase tests ***
    int_buffer buff6(int_list2, 2);
    int_buffer buff7 = generateRandomNumbers(5);
    print(buff6);
    print(buff7);

    int_sorted sorted1(buff6.begin(), buff6.size());
    int_sorted sorted2(buff7.begin(), buff7.size());
    print(sorted1);
    print(sorted2);

    int_sorted sorted3 = sorted1.merge(sorted2);
    print(sorted3);
    return 0;
}



int_buffer generateRandomNumbers(int n)
{
    int_buffer buff(n);
    std::random_device generator;
    std::uniform_int_distribution<int> rnd(0, 100);

    for (int& element : buff)
    {
        element = rnd(generator);
    }
    return buff;
}

int_buffer generateAscendingNumbers(int n)
{
    int_buffer buff(n);
    int counter = 1;

    for (int& element : buff)
    {
        element = counter;
        counter++;
    }
    return buff;
}


void print(const int_buffer& buffer)
{
    std::cout << "Printing buffer addresses\n";
    // Print address and value
    for (const int* i = buffer.begin(); i != buffer.end(); i++)
    {
        std::cout << "Address: " << i << "\t\t" << "Value: " << *i << "\n";
    }
}

void print(const int_sorted& buffer)
{
    std::cout << "Printing sorted buffer addresses\n";
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