

#include "./PhoneBook.hpp"
#include <cstdio>







int main(){
     
     PhoneBook book;
     std::string commnad;

     while (true) {

              std::cout << "Enter command (ADD , SEARCH , EXIT) : ";

               if (std::cin.eof()) 
                         break;
                  
             std::getline(std::cin, commnad);  
              if(commnad == "ADD")
                book.AddContact();
              else if (commnad == "SEARCH")
                book.Search();
              else if (commnad == "EXIT")
                break;
              else
                std::cout << "Invalid command" << std::endl;
     
     }
     return 0;

}