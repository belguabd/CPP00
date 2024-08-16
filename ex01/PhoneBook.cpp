#include "PhoneBook.hpp"

bool SkipWhiteSpace(std::string input)
{
    for (size_t i = 0; input[i]; i++)
        if (!std::isspace(input[i]))
            return (true);
    return (false);
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

    return (input);
}
#include <iomanip>

void PhoneBook::AddContact()
{
    Contact NewContact;
    std::string input;
    input = addNewContact("Enter first name : ", input);
    NewContact.setFirstName(input);
    input.clear();
    input = addNewContact("Enter last name : ", input);
    NewContact.setLastName(input);
    input.clear();
    input = addNewContact("Enter nickname : ", input);
    NewContact.setNickName(input);
    input.clear();
    input = addNewContact("Enter phone number : ", input);
    NewContact.setPhoneNumber(input);
    input.clear();
    input = addNewContact("Enter darkest secret : ", input);
    NewContact.setDarkestSecret(input);
    if (ContactCount < 8)
        this->contact[ContactCount] = NewContact;
    else
        this->contact[ContactCount % 8] = NewContact;
    ContactCount++;
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
    std::cout << "Index      |First Name |Last Name  |Nickname   |" << std::endl;
    for (size_t i = 0; i < ContactCount; i++)
    {
        std::cout << std::setw(11) << i << "|";
        PrintFormatted(contact[i].getFirstName());
        std::cout << "|";
        PrintFormatted(contact[i].getLastName());
        std::cout << "|";
        PrintFormatted(contact[i].getNickName());
        std::cout << "|";
    }
    int index;
    std::cout << std::endl
        << "Enter the index of the contact to display: ";
    std::cin >> index;
    if (index < 0 || index >= ContactCount || std::cin.fail())
        std::cout << "Invalid index , Please try again.";
}
