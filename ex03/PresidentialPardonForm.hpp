#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        const str target;

    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm() throw ();
        PresidentialPardonForm(const PresidentialPardonForm & obj);
        PresidentialPardonForm & operator=(const PresidentialPardonForm & obj);
        PresidentialPardonForm(const str &target);
        void execute(const Bureaucrat &executor) const ;
};

