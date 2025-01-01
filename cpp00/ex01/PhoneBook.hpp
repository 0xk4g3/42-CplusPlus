#ifndef  PHONEBOOK_HPP
# define PHONEBOOK_HPP




#include "Contact.hpp"




class PhoneBook { 
      
      private: 
            Contact Contacts[8];
            int CurrentContact;
      public: 
      
      PhoneBook  ();
      bool isValidInput(const std::string& input, int status);
      std::string truncateText(const std::string& text) const;
    void AddContact();
    void Search();

    

      ~PhoneBook();
      
};
#endif



