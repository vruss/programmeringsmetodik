#include <iostream>
#include <random>
#include "p_queue.h"

struct sell_order
{
    std::string seller_name;
    int price;

    bool operator<(const sell_order& rhs) const
    {
        return price < rhs.price;
    }

    bool operator>(const sell_order& rhs) const
    {
        return rhs < *this;
    }
};

struct buy_order
{
    std::string buyer_name;
    int max_price;

    bool operator<(const buy_order& rhs) const
    {
        return max_price < rhs.max_price;
    }

    bool operator>(const buy_order& rhs) const
    {
        return rhs < *this;
    }
};

int get_random_int();


int main()
{
    p_queue<sell_order> sell_orders;
    p_queue<buy_order> buy_orders;

    // Generate sell orders
    for (int i = 0; i < 7; i++)
    {
        sell_orders.push({"Erik Pendel", get_random_int()});
    }

    for (int i = 0; i < 7; i++)
    {
        sell_orders.push({"Jarl Wallenburg", get_random_int()});
    }
    for (int i = 0; i < 7; i++)
    {
        sell_orders.push({"Joakim von Anka", get_random_int()});
    }

    // Generate buy orders
    for (int i = 0; i < 7; i++)
    {
        buy_orders.push({"Erik Pendel", get_random_int()});
    }

    for (int i = 0; i < 7; i++)
    {
        buy_orders.push({"Jarl Wallenburg", get_random_int()});
    }
    for (int i = 0; i < 7; i++)
    {
        buy_orders.push({"Joakim von Anka", get_random_int()});
    }


    // Check sales
    while (!sell_orders.empty())
    {
        auto sell_ord = sell_orders.pop();

        // Find buyer
        while (!buy_orders.empty())
        {
            auto buy_ord = buy_orders.pop();
            if (sell_ord.price <= buy_ord.max_price && sell_ord.seller_name != buy_ord.buyer_name)
            {
                std::cout << buy_ord.buyer_name << " bought from "
                          << sell_ord.seller_name << " price: "
                          << sell_ord.price << "\n";
                break;
            }
        }
    }

    return 0;
}

int get_random_int()
{
    std::random_device generator;
    std::uniform_int_distribution<int> rnd(10, 40);

    return rnd(generator);
}