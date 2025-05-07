#pragma once

#include <iostream>


typedef std::string str;
class Bureaucrat;

class AForm
{
    private:
        const str name;
        const int gradeToExecute;
        const int gradeToSign;
        bool signedBook;
    public:
        //OCF
        AForm ( void ) ;
        AForm ( str name, int gradeToExecute, int gradeToSign);
        AForm ( const AForm & obj );
        AForm & operator = ( const AForm & obj );
        virtual ~AForm ( void ) throw ();
        
        //getters
        const str getName () const;
        int getGradeToSign () const;
        int getGradeToExecute () const;
        bool getSignedBook () const;

        //exception classes
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

        //member functions
        void beSigned( Bureaucrat & b) ;
        virtual void execute(const Bureaucrat &executor) const = 0;
};

#include "Bureaucrat.hpp"
std::ostream & operator << ( std::ostream &os, const AForm &obj );