

#include "Zombie.hpp"
#include <new>
#include <nl_types.h>






Zombie *newZombie(std::string name){ 
      if (name.empty()) 
        name = "Unnamed"; 
      Zombie *Nzombie = NULL;
    try{

      Nzombie = new Zombie(name);
    }catch(std::bad_alloc& e){
      std::cerr <<"Memory allocation failed :" << e.what() << std::endl;
      return NULL;
    }
    return Nzombie;
}

