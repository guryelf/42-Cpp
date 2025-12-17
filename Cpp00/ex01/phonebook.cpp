#include "phonebook.hpp"

void PhoneBook::display_contact_details(int index)
{
    std::cout << "First Name: " << contacts[index].get_first_name() << std::endl;
    std::cout << "Last Name: " << contacts[index].get_last_name() << std::endl;
    std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].get_phone_number() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].get_darkest_secret() << std::endl;
}

void check_empty(std::string &str, const std::string &prompt)
{
    while (str.empty())
    {
        std::cout << "\n" << "Field cannot be empty. Please enter again: " << "\n";
        std::cin.clear();
        std::cout << prompt;
        std::getline(std::cin, str);
    }
}

void add_info(Contact &contact, const std::string &prompt, void (Contact::*setter)(const std::string))
{
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    check_empty(input, prompt);
    (contact.*setter)(input);
}

void PhoneBook::add_contact()
{
    add_info(contacts[index], "Enter First Name: ", &Contact::set_first_name);
    add_info(contacts[index], "Enter Last Name: ", &Contact::set_last_name);
    add_info(contacts[index], "Enter Nickname: ", &Contact::set_nickname);
    add_info(contacts[index], "Enter Phone Number: ", &Contact::set_phone_number);
    add_info(contacts[index], "Enter Darkest Secret: ", &Contact::set_darkest_secret);

    if (total_contacts < 8)
        total_contacts++;
    
    index = (index + 1) % 8;
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::search_contact()
{
    if (total_contacts == 0)
    {
        std::cout << "No contacts available." << std::endl;
        return;
    }

    std::cout << "Index | First Name | Last Name  | Nickname  " << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < total_contacts; i++)
    {
        std::cout << "  " << i << "  | "
                  << contacts[i].get_first_name().substr(0, 10) << " | "
                  << contacts[i].get_last_name().substr(0, 10) << " | "
                  << contacts[i].get_nickname().substr(0, 10) << std::endl;
    }
}