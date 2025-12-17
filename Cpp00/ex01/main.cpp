#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>

int main()
{
    PhoneBook phonebook;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            phonebook.add_contact();
        }
        else if (command == "SEARCH")
        {
            phonebook.search_contact();
            if (phonebook.get_total_contacts() > 0)
            {
                std::cout << "Enter the index of the contact to view details: ";
                std::string index_str;
                std::getline(std::cin, index_str);
                try
                {
                    if (index_str.empty())
                    {
                        std::cout << "Invalid index." << std::endl;
                    }
                    else
                    {
                        int index = std::stoi(index_str);
                        if (index >= 0 && index < 8)
                        {
                            phonebook.display_contact_details(index);
                        }
                        else
                        {
                            std::cout << "Invalid index." << std::endl;
                        }
                    }
                }
                catch (const std::exception &e)
                {
                    std::cout << "Invalid index." << std::endl;
                }
            }
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "Unknown command. Please try again." << std::endl;
        }
    }

    return 0;
}