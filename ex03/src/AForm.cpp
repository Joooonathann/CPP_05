#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm(void) : _name("Default"), _isSigned(false), _signGrade(1), _execGrade(1) { }

AForm::AForm(const std::string &name, const int &signGrade, const int &execGrade): _name(name), _isSigned(false),_signGrade(signGrade), _execGrade(execGrade)
{
    if (this->_signGrade < 1)
		throw (AForm::GradeTooHighException());
	else if (this->_signGrade > 150)
		throw (AForm::GradeTooLowException());

	if (this->_execGrade < 1)
		throw (AForm::GradeTooHighException());
	else if (this->_execGrade > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(AForm const &copy): _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _execGrade(copy._execGrade) { *this = copy; }

AForm::~AForm(void) { }

AForm const	            &AForm::operator=(const AForm &copy)
{
	this->_isSigned = copy._isSigned;
	return (*this);
}

const std::string       &AForm::getName(void) const { return (this->_name); }

const bool              &AForm::getIsSigned(void) const { return (this->_isSigned); }

const int               &AForm::getSignGrade(void) const { return (this->_signGrade); }

const int               &AForm::getExecGrade(void) const { return (this->_execGrade); }

void                    AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
	throw (AForm::GradeTooLowException());
    this->_isSigned = true;
}

void					AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->_signGrade)
		throw (AForm::GradeTooLowException());
	this->executed();
}

const char          *AForm::GradeTooHighException::what(void) const throw() { return ("Error: grade is too high."); }

const char          *AForm::GradeTooLowException::what(void) const throw() { return ("Error: grade is too low."); }

const char			*AForm::FormNotSignedException::what(void) const throw() { return ("Error: form not signed."); }

std::ostream	&operator<<(std::ostream &str, AForm const &form)
{
	return (str << "AForm: " << form.getName() << ", signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", execution grade: " << form.getExecGrade());
}