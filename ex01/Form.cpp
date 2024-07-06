#include "Form.hpp"

Form::Form() : _name("default Form"), _signed(false), _gradeToSign(50), _gradeToExecute(100) {}
Form::Form( const Form& src ) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}
Form::Form( const std::string& name, int gradeToSign, int gradeToExecute ) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if(this->_gradeToSign > 150 || this->_gradeToExecute > 150)
        throw Form::GradeTooLowException();
    if(this->_gradeToSign < 1 || this->_gradeToExecute < 1)
        throw Form::GradeTooHighException();
} 
Form::~Form() {}

Form& Form::operator=( const Form& rhs )
{
    if(&rhs != this)
        this->_signed = rhs.getSigned();
    return *this;
}

std::string Form::getName() const { return this->_name; }
bool Form::getSigned() const { return this->_signed; }
int Form::getGradeToSign() const { return this->_gradeToSign; }
int Form::getGradeToExecute() const { return this->_gradeToExecute; }

void Form::beSigned( const Bureaucrat& bureaucrat )
{
    if(bureaucrat.getGrade() > this->getGradeToSign())
        throw Form::GradeTooLowException();
    this->_signed = true;
}

std::ostream& operator<<( std::ostream& o, const Form& rhs )
{
    o   << "Name of the form : " << rhs.getName() << std::endl
        << "Signed : " << (rhs.getSigned() ? "Yes" : "No") << std::endl
        << "Minimum grade to sign it : " << rhs.getGradeToSign() << std::endl
        << "Minimum grade to execute it : " << rhs.getGradeToExecute() << std::endl;
    return o;
}

