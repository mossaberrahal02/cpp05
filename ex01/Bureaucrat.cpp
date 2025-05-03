#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : name("defaultName"), grade(150) 
{
    // std::cout << "default constructor\n";
    if(grade > 150)
    {
        throw GradeTooLowException();
    }
    else if(grade < 1)
    {
        throw GradeTooHighException();
    }
}

Bureaucrat::Bureaucrat( str name, int grade ): name(name), grade(grade)
{
    // std::cout << "params constructor "<< endl;
    if(grade > 150)
    {
        throw GradeTooLowException();
    }
    else if(grade < 1)
    {
        throw GradeTooHighException();
    }
}

Bureaucrat::Bureaucrat( const Bureaucrat & obj )
{
    // std::cout << "copy constructor\n";
    *this = obj;
}

Bureaucrat & Bureaucrat::operator=( const Bureaucrat & obj )
{
    // std::cout << "copy assignement oper\n";
    if(this != &obj)
        this->grade = obj.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat( void ) throw()
{
    // std::cout << "destructor\n";
}

const str Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::increment()
{
    grade--;
    if(grade < 1)
    {
        grade++;
        throw Bureaucrat::GradeTooHighException();
    }
}
void Bureaucrat::decrement()
{
    grade++;
    if(grade > 150)
    {
        grade--;
        throw Bureaucrat::GradeTooLowException();
    }
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("high grade");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("low grade");
}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return os;
}