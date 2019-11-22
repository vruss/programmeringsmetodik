#include <iostream>
#include <bits/unique_ptr.h>
#include <vector>
#include "circle.h"
#include "cylinder.h"
#include "rectangle.h"
#include "parallelepiped.h"
#include "rounded_rectangle.h"

typedef std::vector<std::unique_ptr<shape>> shape_uptr;


void get_data(const shape_uptr& shapes);

int main()
{
    char red[4] = "Red";
    char blue[5] = "Blue";

    shape_uptr shapes;

    shapes.push_back(std::make_unique<circle>(red, 2));
    shapes.push_back(std::make_unique<cylinder>(blue, 3, 4));
    shapes.push_back(std::make_unique<rectangle>(blue, 3, 3));
    shapes.push_back(std::make_unique<parallelepiped>(blue, 13, 15, 22));
    shapes.push_back(std::make_unique<rounded_rectangle>(red, 100, 200, 20));

    get_data(shapes);
    return 0;
}

void get_data(const shape_uptr& shapes)
{
    for (auto& s : shapes)
    {
        std::cout << "Colour\t" << s->get_colour()
                  << "\t\tarea: " << s->get_area()
                  << "\n";
    }
}