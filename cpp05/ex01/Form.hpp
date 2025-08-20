#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;
#include <iostream>
class Form{
	 
		private:
			const std::string _name;
			bool _signed;
			const int _grade_sign;
			const int _grade_execute;
		public:
		Form();
		Form(const std::string& name ,const int grade_sign , const int grade_execute);
		Form(const Form& other);
		Form& operator=(const Form& other);
        ~Form();
		// member functions 
		 void beSigned(const Bureaucrat& Bureaucrat);
		// Geters
	    std::string getName()const;
		bool getIsSigned()const;
		int getGradeSign()const;
		int getGradeExecute()const;

		//exception
		class GradeTooHighException : public std::exception {
            public:
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception{ 
            public:
            virtual const char* what() const throw();
			
		};
};


std::ostream& operator<<( std::ostream& out , const Form& Form);


#endif
