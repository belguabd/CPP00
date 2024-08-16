#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contact[8];
    int ContactCount;

public:
    PhoneBook()
    {
        this->ContactCount = 0;
    }
    void AddContact();
    void Search();
    void Exit();
};
