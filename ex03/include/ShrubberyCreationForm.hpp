#pragma once

#include "./AForm.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ~ShrubberyCreationForm(void);

        const ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &copy);
        void	                        executed(void) const;
};