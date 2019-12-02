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

// Predicates
struct comp_date_who_subject
{
    bool operator()(const email& lhs, const email& rhs);
};

struct comp_who_date_subject
{
    bool operator()(const email& lhs, const email& rhs);
};

struct comp_subject_who_date
{
    bool operator()(const email& lhs, const email& rhs);
};


#endif //LAB4_EMAIL_H
