#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
private:
    Contact	contacts[8];
    int		index;
    int		total_contacts;
public:
    PhoneBook() : index(0), total_contacts(0) {}
    ~PhoneBook() {}
    void    add_contact();
    void    search_contact();
    void    display_contact_details(int index);
    int     get_total_contacts() const { return total_contacts; }
};

#endif