#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "monitor.h"
#include "print.h"
#include "is_greater.h"
#include "bin_op.h"
#include "un_op.h"


int main()
{
    monitor monitors_arr[] = {
            {"Ultra-HD",   "LG",    "UHD",   31.5},
            {"SD",         "Brand", "720p",  14.2},
            {"Widescreen", "HP",    "1080p", 27.4},
            {"Widescreen", "BenQ",  "1080p", 23.1},
    };
    unsigned monitor_arr_size = sizeof(monitors_arr) / sizeof(monitor);
    std::vector<monitor> monitors(monitors_arr, monitors_arr + monitor_arr_size);

    // 1.
    std::cout << "\n1\n";
    std::for_each(monitors.begin(), monitors.end(), print());

    // 2.
    std::cout << "\n2\n";
    auto m2 = std::find_if(monitors.begin(), monitors.end(),
                           is_greater(24));
    if (m2 != monitors.end())
    {
        std::cout << *m2 << "\n";
    }

    // 3.
    std::cout << "\n3\n";
    auto m3 = std::adjacent_find(monitors.begin(), monitors.end());
    if (m3 != monitors.end())
    {
        std::cout << *m3 << "\n";
    }

    // 4.
    std::cout << "\n4\n";
    if (std::equal(monitors_arr, monitors_arr + monitor_arr_size,
                   monitors.begin(), monitors.end()))
    {
        std::cout << "The array and vector is equal\n";
    }

    // 5.
    std::cout << "\n5\n";
    int bounds = 1;
    auto m5 = std::search(monitors.begin(), monitors.end(),
                          monitors.begin() + 1, monitors.end() - bounds);
    if (m5 != monitors.end())
    {
        std::for_each(m5, monitors.end() - bounds, print());
    }

    // 6.
    std::cout << "\n6\n";
    auto sum = std::accumulate(monitors.begin(), monitors.end(), 0,
                               bin_op<double>());
    std::cout << "The average inch size is: " << sum / monitor_arr_size << "\n";

    // 7.
    std::cout << "\n7\n";
    std::vector<monitor> monitors2(monitor_arr_size);
    std::transform(monitors.begin(), monitors.end(),
                   monitors2.begin(), un_op<monitor>());
    std::for_each(monitors2.begin(), monitors2.end(), print());

    // 8.
    std::cout << "\n8\n";
//    std::transform(monitors2.begin(), monitors2.end(),
//                   monitors2.begin());
//    return 0;
}