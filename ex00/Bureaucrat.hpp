#pragma once

#include <exception>
#include <iostream>
#include <ostream>

typedef std::string str;
#define endl std::endl

class Bureaucrat
{
    private:
        const str name;
        int grade;
    public:
        Bureaucrat( void ) ;
        Bureaucrat( str name, int grade );
        Bureaucrat( const Bureaucrat & obj );
        Bureaucrat & operator=( const Bureaucrat & obj );
        ~Bureaucrat( void ) throw();

        const str getName() const;
        int getGrade() const;

        void increment();
        void decrement();

        class GradeTooHighException : public std::exception
        {
            public:
                const char * what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                const char * what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);