#include <iostream>

class Contact
{
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;
    public:
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getDarkestSecret();
        void setFirstName(std::string FirstName);
        void setLastName(std::string LastName);
        void setNickName(std::string NickName);
        void setPhoneNumber(std::string PhoneNumber);
        void setDarkestSecret(std::string DarkestSecret);
};