#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm( "ShrubberyCreationForm", 145, 137 ), _target( "default target" ) {}
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& src ) : AForm( src ), _target( src._target ) {}
ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) : AForm( "ShrubberyCreationForm", 145, 137 ), _target( target ) {} 
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& rhs )
{   
    ( void )rhs;
    return *this;
}

void ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
    if ( executor.getGrade() > this->getGradeToExecute() )
        throw AForm::GradeTooLowException();
    else if ( this->getSigned() == false )
        throw AForm::UnsignedException();
    else
    {
        std::ofstream file( ( this->_target + "_shrubbery" ).c_str() );
        if ( file.is_open() )
        {
            file << "        _-_" << std::endl;
            file << "     /~~   ~~\\" << std::endl;
            file << "  /~~         ~~\\" << std::endl;
            file << " {               }" << std::endl;
            file << "  \\  _-     -_  /" << std::endl;
            file << "    ~  \\ //  ~" << std::endl;
            file << " _- -   | | _- _" << std::endl;
            file << "   _ -  | |   -_" << std::endl;
            file << "       // \\\\" << std::endl;
            file.close();
        }
    }
}
