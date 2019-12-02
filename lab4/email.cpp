//
// Created by viro on 2019-11-27.
//

#include "email.h"

/**
 * Constructor
 *
 * @brief Short description
 *
 * @param who dsd
 * @param date as d
 * @param subject as dsa
 */
email::email(std::string who, std::string date, std::string subject)
        : who(who), date(date), subject(subject)
{
}

/**
 * dsidhsad
 * @param os
 * @param email
 * @return
 */
std::ostream& operator<<(std::ostream& os, const email& email)
{
    os << "who: " << email.who << " date: " << email.date << " subject: " << email.subject;
    return os;
}

bool comp_date_who_subject::operator()(const email& lhs, const email& rhs)
{
    {
        if (lhs.date < rhs.date)
        {
            return true;
        }
        if (lhs.date == rhs.date)
        {
            if (lhs.who < rhs.who)
            {
                return true;
            }
        }
        if (lhs.date == rhs.date)
        {
            if (lhs.who == rhs.who)
            {
                if (lhs.subject < rhs.subject)
                {
                    return true;
                }
            }
        }
        return false;
    }
}

bool comp_who_date_subject::operator()(const email& lhs, const email& rhs)
{
    {
        if (lhs.who < rhs.who)
        {
            return true;
        }
        if (lhs.who == rhs.who)
        {
            if (lhs.date < rhs.date)
            {
                return true;
            }
        }
        if (lhs.who == rhs.who)
        {
            if (lhs.date == rhs.date)
            {
                if (lhs.subject < rhs.subject)
                {
                    return true;
                }
            }
        }
        return false;
    }
}

bool comp_subject_who_date::operator()(const email& lhs, const email& rhs)
{
    {
        if (lhs.subject < rhs.subject)
        {
            return true;
        }
        if (lhs.subject == rhs.subject)
        {
            if (lhs.who < rhs.who)
            {
                return true;
            }
        }
        if (lhs.subject == rhs.subject)
        {
            if (lhs.who == rhs.who)
            {
                if (lhs.date < rhs.date)
                {
                    return true;
                }
            }
        }
        return false;
    }
}
