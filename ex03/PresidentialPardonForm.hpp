#ifndef PRESIDENTIAL_PARDON_FORM
#define PRESIDENTIAL_PARDON_FORM

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    const std::string _target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm( const std::string& target );
    PresidentialPardonForm( const PresidentialPardonForm& src );
    ~PresidentialPardonForm();

    PresidentialPardonForm& operator=( const PresidentialPardonForm& rhs );

    void execute( Bureaucrat const & executor ) const;
};

#endif