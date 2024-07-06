#ifndef SHRUBBERY_CREATION_HPP
#define SHRUBBERY_CREATION_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    const std::string _target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm( const std::string& target );
    ShrubberyCreationForm( const ShrubberyCreationForm& src );
    ~ShrubberyCreationForm();

    ShrubberyCreationForm& operator=( const ShrubberyCreationForm& rhs );

    void execute( Bureaucrat const & executor ) const;
};

#endif