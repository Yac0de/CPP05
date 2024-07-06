#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat yanis("Yanis", 2);
        Form formA("FormA", 3, 5);
        std::cout << yanis << std::endl;
        std::cout << formA << std::endl;
        
        yanis.signForm(formA);
        std::cout << formA << std::endl;

        yanis.incrementGrade();
        std::cout << "After increment: " << yanis << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Bureaucrat exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Bureaucrat exception: " << e.what() << std::endl;
    }
    catch (const Form::GradeTooHighException &e)
    {
        std::cerr << "Form exception: " << e.what() << std::endl;
    }
    catch (const Form::GradeTooLowException &e)
    {
        std::cerr << "Form exception: " << e.what() << std::endl;
    }

    try
    {
        // This should throw an exception due to invalid grade
        Bureaucrat joe("Joe", 100);
        std::cout << joe << std::endl;
        Form formB("FormB", 3, 5);
        joe.signForm(formB);
        std::cout << formB << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Bureaucrat exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Bureaucrat exception: " << e.what() << std::endl;
    }

    try
    {
        // This should throw an exception due to invalid grade
        Form formC("FormC", 0, 50);
        std::cout << formC << std::endl;
    }
    catch (const Form::GradeTooHighException &e)
    {
        std::cerr << "Form exception: " << e.what() << std::endl;
    }
    catch (const Form::GradeTooLowException &e)
    {
        std::cerr << "Form exception: " << e.what() << std::endl;
    }

    return 0;
}
