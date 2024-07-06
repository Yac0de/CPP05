#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;
public:
    Form();
    Form( const Form& src );
    Form( const std::string& name, int gradeToSign, int gradeToExecute );
    ~Form();

    Form& operator=( const Form& rhs );

    std::string getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned( const Bureaucrat& bureaucrat );

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
};

std::ostream& operator<<( std::ostream& o, const Form& rhs );

#endif