

#include "PhoneBook.hpp"
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ostream>
#include <string>


PhoneBook::PhoneBook(){ 
       CurrentContact =  0;
       
}


bool PhoneBook::isValidInput(const std::string& input){ 
            if(input.empty())
              return false;
            for (size_t i = 0; i < input.length(); i++) {
                 if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n' && input[i] != '\r')
                           return true;
            }
          return false;
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

   std::cout << "First name :";
   std::getline(std::cin, input);
   while (!(isValidInput(input))) {
       std::cout << "Field cannot be empty.\n";
       std::cout << "First name:";
       std::getline(std::cin, input);     
   }
   Contacts[CurrentContact].setFirstName(input);
   
   std::cout << "Last Name :";
   std::getline(std::cin, input);
   while (!(isValidInput(input))) {
       std::cout << "Field cannot be empty.\n";
       std::cout << "Last name:";
       std::getline(std::cin, input);     
   }
   Contacts[CurrentContact].setLastName(input);

   std::cout << "Nickname :";
   std::getline(std::cin, input);
   while (!(isValidInput(input))) {
       std::cout << "Field cannot be empty.\n";
       std::cout << "Nickname :";
       std::getline(std::cin, input);     
   }
   Contacts[CurrentContact].setNickname(input);

   std::cout << "Phone Number :";
   std::getline(std::cin, input);
   while (!(isValidInput(input))) {
       std::cout << "Field cannot be empty.\n";
       std::cout << "Phone Number :";
       std::getline(std::cin, input);     
   }

   Contacts[CurrentContact].setPhoneNumber(input);
   
   std::cout << "Darkest Secret :";
   std::getline(std::cin, input);
   while (!(isValidInput(input))) {
       std::cout << "Field cannot be empty.\n";
       std::cout << "Darkest Secret :";
       std::getline(std::cin, input);     
   }
   Contacts[CurrentContact].setDarkestSecret(input);

   if (CurrentContact >= 8)
       CurrentContact = 1;
   else
       CurrentContact++;
}

void PhoneBook::Search() { 
   int Index;
   std::string input;
   static int totalContacts = 0;

   if (CurrentContact > totalContacts)
       totalContacts = CurrentContact;
   
   std::cout << std::setw(10) << "CurrentContact" << "|";
   std::cout << std::setw(10) << "first name"<< "|";
   std::cout << std::setw(10) << "last name"<< "|";
   std::cout << std::setw(10) << "nickname"<< "|" << std::endl;
   

   for (int i = 0; i < totalContacts; i++) {
       std::cout << std::setw(10) << i << "|";
       std::cout << std::setw(10) << truncateText(Contacts[i].getFirstname()) << "|";
       std::cout << std::setw(10) << truncateText(Contacts[i].getLastName()) << "|";
       std::cout << std::setw(10) << truncateText(Contacts[i].getNickname())<< "|" << std::endl;
   } 
   

   std::cout << "\nEnter Index to display details :";
   std::getline(std::cin,input);
   
   for (size_t i = 0; i < input.length(); i++) {
       if(!std::isdigit(input[i])) {
           std::cout << "Invalid Index" << std::endl;
           return;
       }
   }
   
   Index = std::atoi(input.c_str());        
   if(Index >= 0 && Index < totalContacts) {
       std::cout << "First Name: " << Contacts[Index].getFirstname() << std::endl;
       std::cout << "Last Name: " << Contacts[Index].getLastName() << std::endl;
       std::cout << "Nickname: " << Contacts[Index].getNickname() << std::endl;
       std::cout << "Phone Number: " << Contacts[Index].getPhoneNumber() << std::endl;
       std::cout << "Darkest Secret: " << Contacts[Index].getDarkestSecret() << std::endl;
   } else {
       std::cout << "The user ID not Available" << std::endl;
   }
}
PhoneBook::~PhoneBook(){

}