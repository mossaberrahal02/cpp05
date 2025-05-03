#include "Form.hpp"

Form::Form( void ) : name("defaultName"), gradeToExecute(150), gradeToSign(150), signedBook(0)
{
    // std::cout << "default constructor\n";
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
    // std::cout << "params constructor "<< endl;
    if(gradeToExecute > 150 || gradeToSign > 150)
    {
        throw GradeTooLowException();
    }
    else if(gradeToExecute < 1 || gradeToSign < 1)
    {
        throw GradeTooHighException();
    }
}

Form::Form( const Form & obj)
{
    *this = obj;
}

Form & Form::operator=( const Form & obj )
{
    // std::cout << "copy assignement oper\n";
    if(this != &obj)
        this->signedBook = obj.getSignedBook();
    return *this;
}

Form::~Form( void ) throw()
{
    // std::cout << "destructor\n";
}

bool Form::getSignedBook() const
{
    return (signedBook);
}

const str Form::getName () const
{
    return (name);
}

const int Form::getGradeToSign () const
{
    return (gradeToSign);
}

const int Form::getGradeToExecute () const
{
    return (gradeToExecute);
}


// void Form::incrementGradeToExecute()
// {
//     gradeToExecute--;
//     if(gradeToExecute < 1)
//     {
//         gradeToExecute++;
//         throw Form::GradeTooHighException();
//     }
// }
// void Form::decrementGradeToExecute()
// {
//     gradeToExecute++;
//     if(gradeToExecute > 150)
//     {
//         gradeToExecute--;
//         throw Form::GradeTooLowException();
//     }
// }
// void Form::increment()
// {
//     grade--;
//     if(grade < 1)
//     {
//         grade++;
//         throw Form::GradeTooHighException();
//     }
// }
// void Form::decrement()
// {
//     grade++;
//     if(grade > 150)
//     {
//         grade--;
//         throw Form::GradeTooLowException();
//     }
// }
