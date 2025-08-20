#ifndef AFORM_HPP
#define AFORM_HPP

class Bureaucrat;
#include <iostream>
#include <fstream>
class AForm{
	 
		private:
			const std::string _name;
			bool _signed;
			const int _grade_sign;
			const int _grade_execute;
		public:
		AForm();
		AForm(const std::string& name ,const int grade_sign , const int grade_execute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
       virtual  ~AForm();
		// member functions 
		 void beSigned(const Bureaucrat& Bureaucrat);
         virtual void execute(const Bureaucrat& Bureaucrat) const = 0;
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
        class TheTargetNotSigned : public std::exception{
            public: 
                virtual const char* what() const throw();
        };
};


std::ostream& operator<<( std::ostream& out , const AForm& Form);


#endif
