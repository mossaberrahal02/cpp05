#include "AForm.hpp"

AForm::AForm( void ) : name("defaultName"), gradeToExecute(150), gradeToSign(150), signedBook(0)
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

AForm::AForm( std::string name, int gradeToExecute, int  gradeToSign): name(name), gradeToExecute(gradeToExecute), gradeToSign(gradeToSign), signedBook(0)
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

AForm::AForm( const AForm & obj):name(obj.name), gradeToExecute(obj.gradeToExecute), gradeToSign(obj.gradeToSign), signedBook(obj.signedBook)
{
}

AForm & AForm::operator=( const AForm & obj )
{
    if(this != &obj)
        this->signedBook = obj.getSignedBook();
    return *this;
}

AForm::~AForm( void ) throw()
{
}

bool AForm::getSignedBook() const
{
    return (signedBook);
}

const str AForm::getName () const
{
    return (name);
}

int AForm::getGradeToSign () const
{
    return (gradeToSign);
}

int AForm::getGradeToExecute () const
{
    return (gradeToExecute);
}

std::ostream & operator << ( std::ostream &os, const AForm &obj )
{
    os << "name = " << obj.getName() << endl; 
    os << "gradeToSign = " << obj.getGradeToSign() << endl;
    os << "getGradeToExecute = " << obj.getGradeToExecute() << endl;
    if(obj.getSignedBook())
        os << "signedBook = 1";
    else
        os << "signedBook = 0";
    return os;
}


const char * AForm::GradeTooHighException::what () const throw ()
{
    return "AForm grade is too high.";
}
const char * AForm::GradeTooLowException::what () const throw ()
{
    return "AForm grade is too low.";
}

const char * AForm::FormNotSignedException::what() const throw ()
{
    return "Form is not signed.";
}

void AForm::beSigned( Bureaucrat & b )
{
    if(this->gradeToSign >= b.getGrade())
        this->signedBook = 1;
    else
        throw GradeTooLowException();
}

