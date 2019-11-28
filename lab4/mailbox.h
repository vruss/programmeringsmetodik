//
// Created by viro on 2019-11-27.
//

#ifndef LAB4_MAILBOX_H
#define LAB4_MAILBOX_H


#include <vector>
#include "email.h"


class mailbox
{
private:
    std::vector<email> emails;

public:
    explicit mailbox(size_t size);

    void sort_date();

    void sort_who();

    void sort_subject();

    void push(const email& element);

    void pop();

    bool empty();

    unsigned long size();

    std::vector<email>::iterator begin();

    std::vector<email>::const_iterator begin() const;

    std::vector<email>::iterator end();

    std::vector<email>::const_iterator end() const;
};

#endif //LAB4_MAILBOX_H
