#include <iostream>
#include <random>
#include "p_queue.h"

struct order
{
    std::string name;
    int price;

    bool operator<(const order& rhs) const
    {
        return price < rhs.price;
    }

    bool operator>(const order& rhs) const
    {
        return rhs < *this;
    }
};

int get_random_int();


int main()
{
    p_queue<order> sell_orders;
    p_queue<order> buy_orders;

    // Generate buy and sell buy_orders
    for (int i = 0; i < 7; i++)
    {
        sell_orders.push({"Erik Pendel", get_random_int()});
        buy_orders.push({"Erik Pendel", get_random_int()});

        sell_orders.push({"Jarl Wallenburg", get_random_int()});
        buy_orders.push({"Jarl Wallenburg", get_random_int()});

        sell_orders.push({"Joakim von Anka", get_random_int()});
        buy_orders.push({"Joakim von Anka", get_random_int()});
    }


    std::cout << sell_orders.size() << " \tsell buy_orders and "
              << buy_orders.size() << " \t buy buy_orders\n";


    // Check sales
    while (!sell_orders.empty())
    {
        auto sell_ord = sell_orders.pop();

        // Find buyer
        while (!buy_orders.empty())
        {
            auto buy_ord = buy_orders.pop();
            if (sell_ord.price <= buy_ord.price)
            {
                std::cout << buy_ord.name << " bought from "
                          << sell_ord.name << " price: "
                          << sell_ord.price << "\n";
                break;
            }
        }
        // Break if no buy buy_orders are left
        if (buy_orders.empty())
            break;
    }


    std::cout << sell_orders.size() << " sell buy_orders left and\t"
              << buy_orders.size() << " buy buy_orders left\n";

    return 0;
}

int get_random_int()
{
    std::random_device generator;
    std::uniform_int_distribution<int> rnd(10, 40);

    return rnd(generator);
}