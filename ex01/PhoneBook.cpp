#include "PhoneBook.hpp"

int PhoneBook::_nbContact = 0;

bool SkipWhiteSpace(std::string input)
{
    for (size_t i = 0; input[i]; i++)
        if (!std::isspace(input[i]))
            return (true);
    return (false);
}

bool isDigit(std::string input)
{
    for (size_t i = 0; i < input.size(); i++)
        if (!std::isdigit(input[i]))
            return (false);
    return (true);
}

std::string addNewContact(std::string MsgInput, std::string input)
{
    std::cout << MsgInput;
    if (!std::getline(std::cin, input))
        std::exit(EXIT_FAILURE);
    while (input.empty() || !SkipWhiteSpace(input))
    {
        std::cout << MsgInput;
        if (!std::getline(std::cin, input))
            std::exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] == '\t')
            input[i] = ' ';
    }
    return (input);
}

void PhoneBook::AddContact()
{
    std::string input;
    input = addNewContact("Enter first name : ", input);
    this->contact[_nbContact].setFirstName(input);
    input.clear();
    input = addNewContact("Enter last name : ", input);
    this->contact[_nbContact].setLastName(input);
    input.clear();
    input = addNewContact("Enter nickname : ", input);
    this->contact[_nbContact].setNickName(input);
    input.clear();
    input = addNewContact("Enter phone number : ", input);
    this->contact[_nbContact].setPhoneNumber(input);
    input.clear();
    input = addNewContact("Enter darkest secret : ", input);
    this->contact[_nbContact].setDarkestSecret(input);
    _nbContact++;
    if (_nbContact == 8)
        _nbContact = 0;
}
void PrintFormatted(std::string contact)
{
    if (contact.size() > 10)
        std::cout << std::setw(10) << contact.substr(0, 10) << ".";
    else
        std::cout << std::setw(11) << contact;
}

void PhoneBook::Search()
{
    std::string input;
    int index;
    if (contact[0].getFirstName().empty())
    {
        std::cout << "Index      |First Name |Last Name  |Nickname   |" << std::endl;
        std::cout << "                  Data empty                   " << std::endl;
        return;
    }
    std::cout << "Index      |First Name |Last Name  |Nickname   |" << std::endl;
    for (int i = 0; i < _nbContact; i++)
    {
        std::cout << std::setw(11) << i << "|";
        PrintFormatted(contact[i].getFirstName());
        std::cout << "|";
        PrintFormatted(contact[i].getLastName());
        std::cout << "|";
        PrintFormatted(contact[i].getNickName());
        std::cout << "|" << std::endl;
    }
    std::cout << "Enter the index of the contact to display: ";
    if (!std::getline(std::cin, input))
        std::exit(0);
    if (!isDigit(input) || input.empty())
    {
        std::cout << "Invalid index , please try again" << std::endl;
        return;
    }
    index = std::stoi(input);
    if (index < 0 || index >= _nbContact)
    {
        std::cout << "Invalid index , please try again" << std::endl;
        return;
    }
    std::cout << "Index      |First Name |Last Name  |Nickname   |" << std::endl;
    std::cout << std::setw(11) << index << "|";
    PrintFormatted(contact[index].getFirstName());
    std::cout << "|";
    PrintFormatted(contact[index].getLastName());
    std::cout << "|";
    PrintFormatted(contact[index].getNickName());
    std::cout << "|" << std::endl;

    std::cout << std::endl
              << "First name is =>" << contact[index].getFirstName() << std::endl;
    std::cout << "Last name is =>" << contact[index].getLastName() << std::endl;
    std::cout << "Nickname is =>" << contact[index].getNickName() << std::endl;
    std::cout << "Phone number is =>" << contact[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret is => " << contact[index].getDarkestSecret() << std::endl;
}

void PhoneBook::Exit()
{
    std::exit(EXIT_SUCCESS);
}
