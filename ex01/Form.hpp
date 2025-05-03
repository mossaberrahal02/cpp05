#pragma once

#include <iostream>

typedef std::string str;

class Form
{
    private:
        bool signedBook;
        const int gradeToSign;
        const int gradeToExecute;
        const str name;
    public:
        Form ( void ) ;
        Form ( str name, int gradeToExecute, int gradeToSign);
        Form ( const Form & obj );
        Form & operator = ( const Form & obj );
        ~Form ( void ) throw ();

        const str getName () const;
        const int getGradeToSign () const;
        const int getGradeToExecute () const;
        bool getSignedBook () const;

        void incrementGradeToSign ();
        void decrementGradeToSign ();
        void incrementGradeToExecute ();
        void decrementGradeToExecute ();

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
};

std::ostream & operator << ( std::ostream &os, const Form &obj );