#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 1);
        Bureaucrat billy("Billy", 150);
        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Alice");

        std::cout << bob << std::endl;
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        bob.signForm(shrubbery);
        bob.signForm(robotomy);
        bob.signForm(pardon);

        std::cout << std::endl;

        billy.signForm(shrubbery);
        billy.signForm(robotomy);
        billy.signForm(pardon);

        std::cout << std::endl;

        bob.executeForm(shrubbery);
        bob.executeForm(robotomy);
        bob.executeForm(pardon);

        std::cout << std::endl;

        billy.executeForm(shrubbery);
        billy.executeForm(robotomy);
        billy.executeForm(pardon);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
