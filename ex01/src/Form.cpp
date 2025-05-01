#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form(void) : _name("Default"), _isSigned(false), _signGrade(1), _execGrade(1) { }

Form::Form(const std::string &name, const int &signGrade, const int &execGrade): _name(name), _isSigned(false),_signGrade(signGrade), _execGrade(execGrade)
{
    if (this->_signGrade < 1)
		throw (Form::GradeTooHighException());
	else if (this->_signGrade > 150)
		throw (Form::GradeTooLowException());

	if (this->_execGrade < 1)
		throw (Form::GradeTooHighException());
	else if (this->_execGrade > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(Form const &copy): _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _execGrade(copy._execGrade) { *this = copy; }

Form::~Form(void) { }

Form const	            &Form::operator=(const Form &copy)
{
	this->_isSigned = copy._isSigned;
	return (*this);
}

const std::string       &Form::getName(void) const { return (this->_name); }

const bool              &Form::getIsSigned(void) const { return (this->_isSigned); }

const int               &Form::getSignGrade(void) const { return (this->_signGrade); }

const int               &Form::getExecGrade(void) const { return (this->_execGrade); }

void                    Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signGrade)
        throw (Form::GradeTooLowException());
    this->_isSigned = true;
}

const char          *Form::GradeTooHighException::what(void) const throw() { return ("Error: grade is too high."); }

const char          *Form::GradeTooLowException::what(void) const throw() { return ("Error: grade is too low."); }

std::ostream	&operator<<(std::ostream &str, Form const &form)
{
	return (str << "Form: " << form.getName() << ", signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", execution grade: " << form.getExecGrade());
}