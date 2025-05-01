#pragma once

#include "./AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        ~PresidentialPardonForm(void);

        const PresidentialPardonForm	&operator=(PresidentialPardonForm const &copy);
        void	                        executed(void) const;
};