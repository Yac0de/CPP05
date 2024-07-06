#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;
public:
    AForm();
    AForm( const AForm& src );
    AForm( const std::string& name, int gradeToSign, int gradeToExecute );
    virtual ~AForm();

    AForm& operator=( const AForm& rhs );

    std::string getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned( const Bureaucrat& bureaucrat );
    virtual void execute( Bureaucrat const & executor ) const = 0;

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw() { return "Too high grade"; }
    };
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw() { return "Too low grade"; }
    };
    class UnsignedException : public std::exception
    {
        public:
            virtual const char* what() const throw() { return "Unsigned form"; }
    };
};

std::ostream& operator<<( std::ostream& o, const AForm& rhs );

#endif