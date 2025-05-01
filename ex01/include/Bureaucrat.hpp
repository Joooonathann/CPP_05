#pragma once

#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
        void                rank(int rank);

    public:
        Bureaucrat(void);
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        ~Bureaucrat(void);

        const Bureaucrat    &operator=(const Bureaucrat &copy);

        const std::string   &getName(void) const;
        const int           &getGrade(void) const;
        void                upGrade(void);
        void                downGrade(void);
        void	            signForm(Form &form);

        class   GradeTooHighException: public std::exception
        {
            public:
                virtual const char     *what(void) const throw();
        };

        class   GradeTooLowException: public std::exception
        {
            public:
                virtual const char     *what(void) const throw();
        };
};

std::ostream    &operator<<(std::ostream &str, const Bureaucrat &bureaucrat);
