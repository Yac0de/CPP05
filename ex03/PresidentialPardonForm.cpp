#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm( "PresidentialPardonForm", 25, 5 ), _target( "default target" ) {}
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& src ) : AForm( src ), _target( src._target ) {}
PresidentialPardonForm::PresidentialPardonForm( const std::string& target ) : AForm( "PresidentialPardonForm", 25, 5 ), _target( target ) {} 
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& rhs )
{
    ( void )rhs;
    return *this;
}

void PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
    if ( executor.getGrade() > this->getGradeToExecute() )
        throw AForm::GradeTooLowException();
    else if ( this->getSigned() == false )
        throw AForm::UnsignedException();
    else
        std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
