#pragma once

#include <string>
#include "AForm.hpp"

class Intern
{
public:
    Intern() {}
    ~Intern() {}
    Intern(const Intern & other) { (void)other; }
    Intern & operator=(const Intern & other) { (void)other; return *this; }

    AForm* makeForm(const std::string & formName, const std::string & target) const;

private:
    typedef AForm* (*FormCreator)(const std::string & target);

    struct FormEntry
    {
        std::string name;
        FormCreator createFunc;
    };

    static AForm* createShrubbery(const std::string & target);
    static AForm* createRobotomy(const std::string & target);
    static AForm* createPresidential(const std::string & target);

    static const FormEntry formEntries[];
};
