#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::Intern( const Intern& src ) { *this = src; }
Intern::~Intern() {}

Intern& Intern::operator=( const Intern& rhs )
{
    ( void )rhs;
    return *this;
}

AForm* Intern::makeForm( const std::string formName, const std::string formTarget )
{
    std::string formNames[] =
    {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };

    AForm* forms[] =
    {
        new PresidentialPardonForm( formTarget ),
        new RobotomyRequestForm( formTarget ),
        new ShrubberyCreationForm( formTarget )
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            for ( int j = 0; j < 3; j++ ) 
            {
                if ( i != j )
                    delete forms[j];
            }
            return forms[i];
        }
    }

    for ( int i = 0; i < 3; i++ )
        delete forms[i];

    std::cout << "Intern can't create " << formName << std::endl;
    return NULL;
}
