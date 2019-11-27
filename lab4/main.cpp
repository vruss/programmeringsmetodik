#include <iostream>
#include "email.h"
#include "mailbox.h"

template <typename T >
void show(const T& vec) {
    for(const auto& mail: vec) {
        std::cout << mail << "\n";
    }
}

int main()
{
    mailbox mails(3);

    email a("Anders", "2002-02-28", "lab 1");
    email b("Anders", "2002-02-28", "lab 2");
    email c("Viro17", "2002-01-28", "lab 2");
    email d("Emilio", "2002-03-28", "lab 3");
    email e("Emilio", "2002-02-30", "lab 1");

    mails.push(a);
    mails.push(b);
    mails.push(c);
    mails.push(d);
    mails.push(e);

    std::cout << "Original mailbox\n";
    show(mails);
//    for(const auto& mail: mails) {
//        std::cout << mail << "\n";
//    }

    std::cout << "\nSorted by date mailbox\n";
    mails.sort_date();
    show(mails);
//    for(const auto& mail: mails) {
//        std::cout << mail << "\n";
//    }

    std::cout << "\nSorted by who mailbox\n";
    mails.sort_who();
    show(mails);
//    for(const auto& mail: mails) {
//        std::cout << mail << "\n";
//    }

    std::cout << "\nSorted by subject mailbox\n";
    mails.sort_subject();
    show(mails);
//    for(const auto& mail: mails) {
//        std::cout << mail << "\n";
//    }

    return 0;
}