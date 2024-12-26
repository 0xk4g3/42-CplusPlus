
#include <iostream>
#include <string>
#include  <cctype>




void toUpper(std::string &str){
    
    
    for (size_t i = 0; i  < str.size() ; i++) {
        str[i] = std::toupper(static_cast<unsigned char>(str[i])); 
    }

}


int main(int ac , char **av ){
    
 
    if(ac  == 1)
        std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
     
    
     for (int i = 1; i < ac  ;  i++) {
             
             std::string str = av[i];
            toUpper(str); 
            std::cout << str ;
     }
     std::cout  << std::endl;
    
}