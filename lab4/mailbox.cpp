//
// Created by viro on 2019-11-27.
//

#include <algorithm>
#include "mailbox.h"

mailbox::mailbox(size_t size)
        : emails(size)
{
}

void mailbox::push(const email& element)
{
    emails.push_back(element);
}

void mailbox::pop()
{
    emails.pop_back();
}

bool mailbox::empty()
{
    return emails.empty();
}

unsigned long mailbox::size()
{
    return emails.size();
}

iterator mailbox::begin()
{
    return emails.begin();
}

const_iterator mailbox::begin() const
{
    return emails.begin();
}


iterator mailbox::end()
{
    return emails.end();
}

const_iterator mailbox::end() const
{
    return emails.end();
}

void mailbox::sort_date()
{
    std::sort(emails.begin(), emails.end(),
              comp_date_who_subject());
}

void mailbox::sort_who()
{
    std::sort(emails.begin(), emails.end(),
              comp_who_date_subject());
}

void mailbox::sort_subject()
{
    std::sort(emails.begin(), emails.end(),
              comp_subject_who_date());
}


