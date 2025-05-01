#pragma once

#include "./AForm.hpp"
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        ~RobotomyRequestForm(void);

        const RobotomyRequestForm	&operator=(RobotomyRequestForm const &copy);
        void	                        executed(void) const;
};