




#include "Bureaucrat.hpp"

int main(){ 
        
    try{ 
        
    Bureaucrat   test("haithem",30);
    Form b("TaxeForm",25,20);
    test.signForm(b);
    std::cout  << b << std::endl;
    }catch(Bureaucrat::GradeTooHighException& e ){ 

            std::cout <<  e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowExecption& e){ 
            std::cout << e.what() << std::endl;
    }catch(Form::GradeTooHighException e){
         std::cout << e.what() << std::endl;
    }catch(Form::GradeTooLowException& e){ 
        std::cout << e.what() << std::endl;
    }
}
