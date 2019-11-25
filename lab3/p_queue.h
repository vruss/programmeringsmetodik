//
// Created by viro on 2019-11-25.
//

#ifndef LAB3_P_QUEUE_H
#define LAB3_P_QUEUE_H


#include <list>

template<typename T>
class p_queue
{
private:
    std::list<T> container;

public:
    p_queue() = default;

    T pop();

    void push(T element);

    int size();

    bool empty();
};

template<typename T>
bool p_queue<T>::empty()
{
    return container.empty();
}

template<typename T>
int p_queue<T>::size()
{
    return container.size();
}

template<typename T>
void p_queue<T>::push(T element)
{
    container.push_back(element);
    container.sort();
}

template<typename T>
T p_queue<T>::pop()
{
    auto T2 = container.front();
    container.pop_front();
    return T2;
}


#endif //LAB3_P_QUEUE_H
