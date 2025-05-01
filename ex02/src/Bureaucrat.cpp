#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

Bureaucrat::Bureaucrat(void): _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name)
{
    if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat(void) { }

const Bureaucrat    &Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this != &copy)
        this->_grade = copy._grade;
    return (*this);
}

const std::string   &Bureaucrat::getName(void) const { return (this->_name); }

const int           &Bureaucrat::getGrade(void) const { return (this->_grade); }

void                Bureaucrat::rank(int rank)
{
    if (rank < 1)
        throw (Bureaucrat::GradeTooHighException());
    else if (rank > 150)
        throw (Bureaucrat::GradeTooLowException());
}

void                Bureaucrat::upGrade(void)
{
    this->rank(this->_grade - 1);
    this->_grade--;
}

void                Bureaucrat::downGrade(void)
{
    this->rank(this->_grade + 1);
    this->_grade++;
}

void	            Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because: " << e.what() << std::endl;
	}
}

void				Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " execute " << form.getName() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << this->_name << " cannot execute " << form.getName() << " because: " << e.what() << std::endl;
	}
}

const char          *Bureaucrat::GradeTooHighException::what(void) const throw() { return ("Error: grade is too high."); }

const char          *Bureaucrat::GradeTooLowException::what(void) const throw() { return ("Error: grade is too low."); }

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat)
{
	return (str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}