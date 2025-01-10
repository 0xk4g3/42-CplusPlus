

#include "Zombie.hpp"






int main(){
     
     Zombie **NewZombie = new  Zombie*[5];
        for(int i  = 0 ;  i <  5 ; i++){
             NewZombie[i] =  new Zombie("haithem");
        }
        for(int i  = 0 ;  i <  5 ; i++){
             NewZombie[i]->announce();
        }
          for(int i  = 0 ;  i <  5 ; i++){
              delete  NewZombie[i];
        }
       delete  [] NewZombie;
     randomChump("bendjaballah");
     randomChump("bendjaballah");

     randomChump("bendjaballah");

     randomChump("bendjaballah");

     randomChump("bendjaballah");
     randomChump("bendjaballah");


     return 0;
}