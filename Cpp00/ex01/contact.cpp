#include "contact.hpp"

void    Contact::set_first_name(const std::string str)
{
    this->first_name = str;
}
void    Contact::set_last_name(const std::string str)
{
    this->last_name = str;
}
void    Contact::set_nickname(const std::string str)
{
    this->nickname = str;
}
void    Contact::set_phone_number(const std::string str)
{
    this->phone_number = str;
}
void    Contact::set_darkest_secret(const std::string str)
{
    this->darkest_secret = str;
}
std::string	Contact::get_first_name() const
{
    return first_name;
}
std::string	Contact::get_last_name() const
{
    return last_name;
}
std::string	Contact::get_nickname() const
{
    return nickname;
}
std::string	Contact::get_phone_number() const
{
    return phone_number;
}
std::string	Contact::get_darkest_secret() const
{
    return darkest_secret;
}