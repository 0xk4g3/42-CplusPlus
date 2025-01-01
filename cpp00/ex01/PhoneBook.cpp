

#include "PhoneBook.hpp"


PhoneBook::PhoneBook(){ 
       CurrentContact =  0;
       
}


bool PhoneBook::isValidInput(const std::string& input, int status) { 
    
    if (input.empty() || input.find_first_not_of(" \t\n\r") == std::string::npos)
        return false;

    switch (status) {
        case 0: 
            for (size_t i = 0; i < input.length(); i++) {
                if (!std::isalpha(input[i]) && !std::isspace(input[i]))
                    return false;
            }
            break;
            
        case 1:
                if(input.length() > 16)
                        return false;
            for (size_t i = 0; i < input.length(); i++) {
                if (!std::isdigit(input[i]) && input[i] != '+' && input[i] != '-' 
                    && input[i] != ' ' && input[i] != '(' && input[i] != ')')
                    return false;
            }
           
            if (input.find_first_of("0123456789") == std::string::npos)
                return false;
            break;
            
        case 2: 
            for (size_t i = 0; i < input.length(); i++) {
                if (!std::isprint(input[i]))
                    return false;
            }
            break;
    }
    return true;
}

std::string PhoneBook::truncateText(const std::string& text) const {
    if(text.length() > 10)
        return text.substr(0,9) + ".";
    return text;
}


void PhoneBook::AddContact() {
    std::string input;
   
    if (CurrentContact >= 8) 
        CurrentContact = 0;

 
    std::cout << "First name: ";
    std::getline(std::cin, input);
    while (!isValidInput(input, 0)) {
        std::cout << "Invalid input. Name must contain only letters.\n";
        std::cout << "First name: ";
        std::getline(std::cin, input);     
    }
    Contacts[CurrentContact].setFirstName(input);

    std::cout << "Last name: ";
    std::getline(std::cin, input);
    while (!isValidInput(input, 0)) {
        std::cout << "Invalid input. Name must contain only letters.\n";
        std::cout << "Last name: ";
        std::getline(std::cin, input);     
    }
    Contacts[CurrentContact].setLastName(input);

 
    std::cout << "Nickname: ";
    std::getline(std::cin, input);
    while (!isValidInput(input, 0)) {
        std::cout << "Invalid input. Nickname must contain only letters.\n";
        std::cout << "Nickname: ";
        std::getline(std::cin, input);     
    }
    Contacts[CurrentContact].setNickname(input);

    std::cout << "Phone number: ";
    std::getline(std::cin, input);
    while (!isValidInput(input, 1)) {
        std::cout << "Invalid input. Phone number must contain digits and optional +, -, (, ) or not more than 16 digits\n";
        std::cout << "Phone number: ";
        std::getline(std::cin, input);     
    }
    Contacts[CurrentContact].setPhoneNumber(input);
   
    // Darkest secret
    std::cout << "Darkest secret: ";
    std::getline(std::cin, input);
    while (!isValidInput(input, 2)) {
        std::cout << "Invalid input. Secret cannot be empty or contain non-printable characters.\n";
        std::cout << "Darkest secret: ";
        std::getline(std::cin, input);     
    }
    Contacts[CurrentContact].setDarkestSecret(input);

    CurrentContact++;
}

void PhoneBook::Search() { 
    if (CurrentContact == 0) {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }
    static int StaticIndex= 0;
    if(CurrentContact > StaticIndex)
            StaticIndex = CurrentContact;

    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nickname" << "|" << std::endl;

    for (int i = 0; i < StaticIndex; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncateText(Contacts[i].getFirstname()) << "|";
        std::cout << std::setw(10) << truncateText(Contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << truncateText(Contacts[i].getNickname()) << "|" << std::endl;
    }

    std::string input;
    std::cout << "\nEnter index to display: ";
    std::getline(std::cin, input);

    if (input.empty()) {
        std::cout << "Error: Empty index" << std::endl;
        return;
    }

    for (size_t i = 0; i < input.length(); i++) {
        if (!std::isdigit(input[i])) {
            std::cout << "Error: Invalid index" << std::endl;
            return;
        }
    }

    int index = std::atoi(input.c_str());
    if (index >= 0 && index < CurrentContact) {
        std::cout << "First Name: " << Contacts[index].getFirstname() << std::endl;
        std::cout << "Last Name: " << Contacts[index].getLastName() << std::endl;
        std::cout << "Nickname: " << Contacts[index].getNickname() << std::endl;
        std::cout << "Phone Number: " << Contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << Contacts[index].getDarkestSecret() << std::endl;
    } else {
        std::cout << "Error: Index out of range" << std::endl;
    }
}
PhoneBook::~PhoneBook(){

}