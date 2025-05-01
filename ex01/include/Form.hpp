#pragma once

#include <stdio.h>
#include <stdexcept>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _execGrade;
    public:
        Form(void);
        Form(const std::string &name, const int &signGrade, const int &execGrade);
        Form(const Form &copy);
        ~Form(void);

        Form const	&operator=(Form const &copy);

        const std::string       &getName(void) const;
        const bool              &getIsSigned(void) const;
        const int               &getSignGrade(void) const;
        const int               &getExecGrade(void) const;
        void                    beSigned(Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char      *what(void) const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char      *what(void) const throw();
        };
};

std::ostream	&operator<<(std::ostream &str, Form const &form);