#include <cstdlib>
#include <ctime>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm( "RobotomyRequestForm", 72, 45 ), _target( "default target" ) {}
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& src ) : AForm( src ), _target( src._target ) {}
RobotomyRequestForm::RobotomyRequestForm( const std::string& target ) : AForm( "RobotomyRequestForm", 72, 45 ), _target( target ) {}
RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& rhs )
{
    ( void )rhs;
    return *this;
}

void RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
    if ( executor.getGrade() > this->getGradeToExecute() )
        throw AForm::GradeTooLowException();
    else if ( this->getSigned() == false )
        throw AForm::UnsignedException();
    else
    {
        std::srand( std::time(0) );
        int randomValue1or0 = std::rand() % 2;
        std::cout << "BZZZ BZZZT! ";
        if ( randomValue1or0 )
            std::cout << this->_target << " has been robotomized successfully.";
        else
            std::cout << "Robotomy on " << this->_target << " failed.";
        std::cout << std::endl;
    }
}
