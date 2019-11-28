#include <iostream>
#include <vector>
#include "monitor.h"
#include "print.h"


int main()
{
    monitor monitors_arr[] = {
            {"Widescreen", "BenQ",  "1080p", 23.1},
            {"Ultra-HD",   "LG",    "UHD",   31.5},
            {"SD",         "Brand", "720p",  14.2},
    };
    unsigned monitor_arr_size = sizeof(monitors_arr) / sizeof(monitor);

    std::vector<monitor> monitors(monitors_arr, monitors_arr + monitor_arr_size);

    for (const auto& m : monitors)
    {
        print a;
        a(m);
    }

    return 0;
}