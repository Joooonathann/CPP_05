#include "../include/Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern const &copy) { *this = copy; }

Intern::~Intern(void) {}

Intern const	&Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

static AForm* createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &type, const std::string &target)
{
	const std::string forms[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*creators[])(const std::string&) = {
		createShrubbery,
		createRobotomy,
		createPresidential
	};

	for (int i = 0; i < 3; ++i) {
		if (type == forms[i]) {
			std::cout << "Intern creates " << type << std::endl;
			return creators[i](target);
		}
	}

	std::cerr << "Error: form \"" << type << "\" does not exist." << std::endl;
	return (NULL);
}