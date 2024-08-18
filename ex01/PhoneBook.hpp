#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
private:
    Contact contact[8];
    static int _nbContact;
    

public:
    PhoneBook(){};
    void AddContact();
    void Search();
    void Exit();
};
