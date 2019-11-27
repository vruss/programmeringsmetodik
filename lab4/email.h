//
// Created by viro on 2019-11-27.
//

#ifndef LAB4_EMAIL_H
#define LAB4_EMAIL_H


#include <string>
#include <ostream>

class email
{
private:
    std::string who;
    std::string date;
    std::string subject;

public:
    email() = default;

    email(std::string who, std::string date, std::string subject);

    friend std::ostream& operator<<(std::ostream& os, const email& email);

    // Predicates
    friend struct comp_date_who_subject;

    friend struct comp_who_date_subject;

    friend struct comp_subject_who_date;

};

// Predicate implementations
struct comp_date_who_subject
{
    bool operator()(const email& lhs, const email& rhs)
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
};

struct comp_who_date_subject
{
    bool operator()(const email& lhs, const email& rhs)
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
};

struct comp_subject_who_date
{
    bool operator()(const email& lhs, const email& rhs)
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
};


#endif //LAB4_EMAIL_H
