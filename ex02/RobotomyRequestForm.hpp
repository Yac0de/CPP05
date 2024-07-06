#ifndef ROBOTOMY_REQUEST_FORM
#define ROBOTOMY_REQUEST_FORM

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    const std::string _target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm( const std::string& target );
    RobotomyRequestForm( const RobotomyRequestForm& src );
    ~RobotomyRequestForm();

    RobotomyRequestForm& operator=( const RobotomyRequestForm& rhs );

    void execute( Bureaucrat const & executor ) const;
};

#endif