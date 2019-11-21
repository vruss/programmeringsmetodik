#include <iostream>
#include "circle.h"

void get_data(shape* shapes, size_t size);

int main()
{
    size_t arr_size = 10;
    char colour1[4] = "Red";
    char colour2[5] = "Blue";

    shape* shapes;

    // Kolla på vector och std::Fill
    shapes[0] = circle(colour1, 2);

     circle c(colour2, 4);
    shapes[1] = &c;

    get_data(shapes, arr_size);
    return 0;
}

void get_data(shape* shapes, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "Colour\t" << shapes->get_colour()
                  << "\tarea: " << shapes->get_area()
                  << "\n";
        shapes++;
    }
}