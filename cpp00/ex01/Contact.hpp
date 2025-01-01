#ifndef  CONTACT_HPP
# define CONTACT_HPP

 
#include <cstdio>
#include <string>
#include <cstdio>





class Contact  { 
     

        private: 

                std::string FirstName;
                std::string LastName;
                std::string Nickname;
                std::string PhoneNumber;
                std::string DarkestSecret;
        public:
         Contact();
           
        void setFirstName (std::string fname);
        void setLastName(std::string lname);
        void setNickname(std::string Nname);
        void setPhoneNumber(std::string Pnumber);
        void setDarkestSecret(std::string Dsecret);

        std::string getFirstname() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
    ~Contact();
     
};
#endif