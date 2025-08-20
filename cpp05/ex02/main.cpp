




#include "Bureaucrat.hpp"

int main(){ 
        
    try{ 
        
    Bureaucrat   test("haithem",30);
    AForm b("TaxeAForm",25,20);
    test.signForm(b);
    std::cout  << b << std::endl;
    }catch(Bureaucrat::GradeTooHighException& e ){ 

            std::cout <<  e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowExecption& e){ 
            std::cout << e.what() << std::endl;
    }catch(AForm::GradeTooHighException e){
         std::cout << e.what() << std::endl;
    }catch(AForm::GradeTooLowException& e){ 
        std::cout << e.what() << std::endl;
    }
}
