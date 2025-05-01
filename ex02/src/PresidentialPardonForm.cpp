#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm::AForm("PresidentialPardonForm", 25, 5), _target("null") { }

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm::AForm("PresidentialPardonForm", 25, 5), _target(target) { }

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy): AForm::AForm(copy), _target(copy._target) { }

PresidentialPardonForm::~PresidentialPardonForm(void) { }

PresidentialPardonForm const	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

void                            PresidentialPardonForm::executed(void) const
{
    std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}