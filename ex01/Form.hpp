#pragma once

#include "Bureaucrat.hpp"
#include <iostream>


typedef std::string str;
class Bureaucrat;
class Form
{
    private:
        const str name;
        const int gradeToExecute;
        const int gradeToSign;
        bool signedBook;
    public:
        Form ( void ) ;
        Form ( str name, int gradeToExecute, int gradeToSign);
        Form ( const Form & obj );
        Form & operator = ( const Form & obj );
        ~Form ( void ) throw ();
        
        const str getName () const;
         int getGradeToSign () const;
         int getGradeToExecute () const;
        bool getSignedBook () const;

        class GradeTooHighException : public std::exception
        {
            public:
                const char * what () const throw ();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                const char * what () const throw ();
        };

        void beSigned( Bureaucrat & b) ;
};
#include "Bureaucrat.hpp"
std::ostream & operator << ( std::ostream &os, const Form &obj );