#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default bureaucrat"), _grade(100) {}
Bureaucrat::Bureaucrat( const Bureaucrat& src ) : _name(src._name), _grade(src._grade) {}
Bureaucrat::Bureaucrat( const std::string& name, int grade ) : _name(name), _grade(grade)
{
    if(this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if(this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}
Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& rhs )
{
    if(&rhs != this)
        this->_grade = getGrade();
    return *this;
}

std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs )
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
    return o;
}

std::string Bureaucrat::getName() const { return this->_name; }
int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::incrementGrade()
{
    if(this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if(this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}