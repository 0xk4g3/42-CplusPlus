


#include "Contact.hpp"




Contact::Contact() { 
    FirstName = "";
    LastName = "";
    Nickname = "";
    PhoneNumber = "";
    DarkestSecret = "";
}

void Contact::setFirstName(std::string fname){
          FirstName  = fname  ;
}

void Contact::setLastName(std::string lname) {

    LastName = lname;
}

 void Contact::setNickname(std::string Nname) { 
             Nickname = Nname;
}
void  Contact::setPhoneNumber(std::string Pnumber) { 
            PhoneNumber = Pnumber;
}
void Contact::setDarkestSecret(std::string Dsecret) { 
             DarkestSecret = Dsecret ;
}
std::string  Contact::getFirstname() const{

        return FirstName;
}

std::string Contact::getLastName() const {
        return LastName;
}

std::string Contact::getNickname()const{
    return Nickname;
}

std::string Contact::getPhoneNumber()const {
     return PhoneNumber;
}
std::string Contact::getDarkestSecret()const { 
    return  DarkestSecret;
}

Contact::~Contact(){}