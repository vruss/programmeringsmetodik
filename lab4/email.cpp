//
// Created by viro on 2019-11-27.
//

#include "email.h"

email::email(std::string who, std::string date, std::string subject)
        : who(who), date(date), subject(subject)
{
}

std::ostream& operator<<(std::ostream& os, const email& email)
{
    os << "who: " << email.who << " date: " << email.date << " subject: " << email.subject;
    return os;
}
