#include "PhoneBook.hpp"

int main()
{
    PhoneBook PB;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH ,EXIT) : ";
        if (!std::getline(std::cin, command))
            return (0);
        if (command == "ADD")
            PB.AddContact();
        else if (command == "SEARCH")
            PB.Search();
        else if (command == "EXIT")
            break;
    }
}
