#ifndef CAT_HPP
#define CAT_HPP


#include "Animal.hpp"


class Cat : public Animal{ 

	public: 
	  Cat(const Cat& other);    
      Cat& operator=(const Cat& other);
	  Cat();
	  virtual ~Cat();
	  void makeSound() const;
};



#endif
