#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat yanis("Yanis", 2);
        std::cout << yanis << std::endl;
        
        yanis.incrementGrade();
        std::cout << "After increment: " << yanis << std::endl;

        yanis.decrementGrade();
        std::cout << "After decrement: " << yanis << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        // This should throw an exception due to invalid grade
        Bureaucrat joe("Joe", 151);
        std::cout << joe << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        // This should throw an exception due to invalid grade
        Bureaucrat mike("Mike", 0);
        std::cout << mike << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
