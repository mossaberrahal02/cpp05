#include "Form.hpp"

Form::Form( void ) : name("defaultName"), gradeToExecute(150), gradeToSign(150), signedBook(0)
{
    if(gradeToExecute > 150 || gradeToSign > 150)
    {
        throw GradeTooLowException();
    }
    else if(gradeToExecute < 1 || gradeToSign < 1)
    {
        throw GradeTooHighException();
    }
}

Form::Form( str name, int gradeToExecute, int  gradeToSign): name(name), gradeToExecute(gradeToExecute), gradeToSign(gradeToSign), signedBook(0)
{
    if(gradeToExecute > 150 || gradeToSign > 150)
    {
        throw GradeTooLowException();
    }
    else if(gradeToExecute < 1 || gradeToSign < 1)
    {
        throw GradeTooHighException();
    }
}

Form::Form( const Form & obj):name(obj.name), gradeToExecute(obj.gradeToExecute), gradeToSign(obj.gradeToSign), signedBook(obj.signedBook)
{
}

Form & Form::operator=( const Form & obj )
{
    if(this != &obj)
        this->signedBook = obj.getSignedBook();
    return *this;
}

Form::~Form( void ) throw()
{
}

bool Form::getSignedBook() const
{
    return (signedBook);
}

const str Form::getName () const
{
    return (name);
}

int Form::getGradeToSign () const
{
    return (gradeToSign);
}

int Form::getGradeToExecute () const
{
    return (gradeToExecute);
}

std::ostream & operator << ( std::ostream &os, const Form &obj )
{
    os << "name = " << obj.getName() << "\n"; 
    os << "gradeToSign = " << obj.getGradeToSign() << "\n";
    os << "getGradeToExecute = " << obj.getGradeToExecute() << "\n";
    if(obj.getSignedBook())
        os << "signedBook = 1";
    else
        os << "signedBook = 0";
    return os;
}


const char * Form::GradeTooHighException::what () const throw ()
{
    return "Form grade is too high.";
}
const char * Form::GradeTooLowException::what () const throw ()
{
    return "Form grade is too low.";
}

void Form::beSigned( Bureaucrat & b )
{
    if(this->gradeToSign >= b.getGrade())
        this->signedBook = 1;
    else
        throw GradeTooLowException();
}
