#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
class Bureaucrat{ 
      private:
        const std::string _name;
         int _grade;
         
         
      public:
         Bureaucrat();
         Bureaucrat(const std::string& name , int grade);
         ~Bureaucrat(); 
         Bureaucrat(const Bureaucrat& src);
         Bureaucrat& operator=(const Bureaucrat &other);
        
          std::string getName() const;
          int getGrade() const;

           void  incrementGrade();
           void  decrementGrade();
           void  signForm(AForm& form);      
      class GradeTooHighException : public std::exception{
            public:
                 virtual const char* what()  const throw(){ 
                       return "Grade is too high! (Must be between 1 and 150)";
                 }
        };
      class GradeTooLowExecption: public std::exception{
     
                public: 
                    virtual const char* what() const throw(){
                          return "Grade is too low! (Must be between 1 and 150)";
                    }
          };


};

std::ostream& operator<<(std::ostream& out , const Bureaucrat& Bureaucrat);
#endif
