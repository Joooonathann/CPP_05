#pragma once

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:

    public:
        Intern(void);
        Intern(const Intern &copy);
        ~Intern(void);

        const Intern	&operator=(Intern const &copy);
        AForm	        *makeForm(std::string const &type, std::string const &target);
};
