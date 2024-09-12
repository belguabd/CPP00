#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
private:
    Contact contact[8];
    static int _nbContact;
    static int _nbrContact;

public:
    void AddContact();
    void Search();
    void Exit();

};