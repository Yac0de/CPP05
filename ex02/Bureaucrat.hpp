#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat( const Bureaucrat& src );
    Bureaucrat( const std::string& name, int grade );
    ~Bureaucrat();

    Bureaucrat& operator=( const Bureaucrat& rhs );

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm( AForm& form );
    void executeForm( AForm const & form ) const;

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

std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs );

#endif