#include "AForm.hpp"

AForm::AForm() : _name("default AForm"), _signed(false), _gradeToSign(50), _gradeToExecute(100) {}
AForm::AForm( const AForm& src ) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}
AForm::AForm( const std::string& name, int gradeToSign, int gradeToExecute ) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if(this->_gradeToSign > 150 || this->_gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    if(this->_gradeToSign < 1 || this->_gradeToExecute < 1)
        throw AForm::GradeTooHighException();
} 
AForm::~AForm() {}

AForm& AForm::operator=( const AForm& rhs )
{
    if(&rhs != this)
        this->_signed = rhs.getSigned();
    return *this;
}

std::string AForm::getName() const { return this->_name; }
bool AForm::getSigned() const { return this->_signed; }
int AForm::getGradeToSign() const { return this->_gradeToSign; }
int AForm::getGradeToExecute() const { return this->_gradeToExecute; }

void AForm::beSigned( const Bureaucrat& bureaucrat )
{
    if(bureaucrat.getGrade() > this->getGradeToSign())
        throw AForm::GradeTooLowException();
    this->_signed = true;
}

std::ostream& operator<<( std::ostream& o, const AForm& rhs )
{
    o   << "Name of the form : " << rhs.getName() << std::endl
        << "Signed : " << (rhs.getSigned() ? "Yes" : "No") << std::endl
        << "Minimum grade to sign it : " << rhs.getGradeToSign() << std::endl
        << "Minimum grade to execute it : " << rhs.getGradeToExecute() << std::endl;
    return o;
}

