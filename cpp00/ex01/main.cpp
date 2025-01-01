

#include "./PhoneBook.hpp"








int main() {
    PhoneBook book;
    std::string command;
    
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        
        std::getline(std::cin, command);
        if (std::cin.eof()) {
            std::cout << std::endl;
            break;
        }
        
        if (command == "ADD")
            book.AddContact();
        else if (command == "SEARCH")
            book.Search();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command" << std::endl;
    }
    return 0;
}