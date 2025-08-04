
#include "Form.hpp"

Form::Form():_name("Default") , _signed(1),_grade_sign(10),_grade_execute(25){

	std::cout << "Constructor called" << std::endl;
}


Form::Form(const std::string& name 
		,const int grade_sign 
		, const int grade_execute): _name(name), _signed(false),
	_grade_sign(grade_sign),
	_grade_execute(grade_execute) {
   
		
		if(grade_sign <  1 || grade_sign > 150)
			throw GradeTooHighException();
		if(grade_execute < 1 || grade_execute > 150 )	
			throw GradeTooHighException();

	std::cout << "Form " << _name <<  " created"<<  std::endl;
}

Form::Form(const Form &other):_name(other._name) ,_signed(other._signed), _grade_sign(other._grade_sign) , _grade_execute(other._grade_execute){ 

		std::cout << "copy constructor" << std::endl;
}

Form& Form::operator=(const Form& other){ 
     
	if(this != &other)
	   _signed = other._signed;
	
     return (*this);

}

std::string Form::getName() const{ 

    return (_name);
}
bool Form::getIsSigned() const {
     
    return (_signed);
} 
int Form::getGradeSign() const { 
    return (_grade_sign);
}
int Form::getGradeExecute() const {
     return (_grade_execute);
}


