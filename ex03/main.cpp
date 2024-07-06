#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 1);
        Bureaucrat billy("Billy", 150);
        Intern someRandomIntern;

        AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "Home");
        AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Alice");
        AForm* unknown = someRandomIntern.makeForm("unknown form", "Unknown");

        if (shrubbery)
        {
            std::cout << *shrubbery << std::endl;
            bob.signForm(*shrubbery);
            bob.executeForm(*shrubbery);
            billy.signForm(*shrubbery);
            billy.executeForm(*shrubbery);
        }

        if (robotomy)
        {
            std::cout << *robotomy << std::endl;
            bob.signForm(*robotomy);
            bob.executeForm(*robotomy);
            billy.signForm(*robotomy);
            billy.executeForm(*robotomy);
        }

        if (pardon)
        {
            std::cout << *pardon << std::endl;
            bob.signForm(*pardon);
            bob.executeForm(*pardon);
            billy.signForm(*pardon);
            billy.executeForm(*pardon);
        }

        delete shrubbery;
        delete robotomy;
        delete pardon;
        delete unknown;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
