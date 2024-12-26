

#include <iostream>
#include <string>
#include  <cctype>




void   ChangeToUpperCase(std::string &UserInput){
        
         
         for(std::string::iterator character = UserInput.begin() ;character != UserInput.end() ; character++){
               if(*character >= 'a'  &&  *character <=  'z')
                        *character -= 32; 
         }
}


int main(int ac , char **av ){
    
 
    if(ac  == 1){
        std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
            return 0;
    }
     
    for(int  i =  1 ; i < ac ; i++){
         
         std::string UserText = av[i];
         ChangeToUpperCase(UserText);
         std::cout << UserText ;   
    }
    std::cout << std::endl;
    return 0;
}