#pragma once

#include <stdio.h>
#include <stdexcept>

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _execGrade;
    public:
        AForm(void);
        AForm(const std::string &name, const int &signGrade, const int &execGrade);
        AForm(const AForm &copy);
        virtual ~AForm(void);

        AForm const	&operator=(AForm const &copy);

        const std::string       &getName(void) const;
        const bool              &getIsSigned(void) const;
        const int               &getSignGrade(void) const;
        const int               &getExecGrade(void) const;
        void                    beSigned(Bureaucrat &bureaucrat);
        void                    execute(Bureaucrat const &executor) const;
        virtual void	        executed(void) const = 0;


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

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char      *what(void) const throw();
        };
};

std::ostream	&operator<<(std::ostream &str, AForm const &form);