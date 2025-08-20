

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("Default"),_grade(20){ 
        
        std::cout<< "Bureaucrat default constructor called" << std::endl;
}



Bureaucrat::Bureaucrat(const std::string& name , int grade):_name(name){
       
    std::cout << "Bureaucrat constructor called for " << name << std::endl; 
   
    if(grade < 1 )
            throw GradeTooHighException();
    if(grade > 150)
            throw GradeTooLowExecption();
        _grade = grade;
    
}


//----> Getter start <-----//  

std::string Bureaucrat::getName()const { 
   
        return (_name);
}

int Bureaucrat::getGrade() const{
    
    return (_grade);
}
//----> End Of Getters <----//


void Bureaucrat::incrementGrade(){

        if(_grade -1 < 1) 
           throw GradeTooHighException();
        
        _grade--;
  std::cout << _name << " promoted to grade " << _grade << std::endl;
}

void Bureaucrat::decrementGrade() {
    if(_grade + 1 > 150)
       throw GradeTooLowExecption(); 
    _grade++;
    std::cout << _name << " demoted to grade " << _grade << std::endl;
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){ 

       if(this != &other){
          _grade = other._grade;

       }
     return *this;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other):_name(other._name),_grade(other._grade){ 
             
     std::cout << "Bureaucrat copy constructor called" << std::endl;
}

//destructor
Bureaucrat::~Bureaucrat(){
     
std::cout << "Bureaucrat destructor called for " << _name << std::endl;
}

void Bureaucrat::signForm(AForm& form){

    try{ 
        form.beSigned(*this);
    std::cout << _name << " signed " << form.getName() << std::endl;
    }catch(std::exception& e){
            
  std::cout << _name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;

    }
}

//Ostream
std::ostream& operator<<(std::ostream& out , const Bureaucrat& Bureaucrat){
        
     out  << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl;
    return out;
}



