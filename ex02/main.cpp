#include "./include/Bureaucrat.hpp"
#include "./include/AForm.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include <iostream>

void	print_separator(const std::string& title)
{
	std::cout << "\n=== " << title << " ===\n\n";
}

void	test_execution_without_signature(Bureaucrat& b, AForm& f1, AForm& f2, AForm& f3)
{
	print_separator("Test: Execution sans signature");
	try
	{
		std::cout << b << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;
		b.executeForm(f1);
		b.executeForm(f2);
		b.executeForm(f3);
	}
	catch (const std::exception &e)
	{
		std::cout << "Erreur : " << e.what() << std::endl;
	}
}

void	test_signature_without_exec_rights(Bureaucrat& signer, Bureaucrat& executor, AForm& form)
{
	print_separator("Test: Signature OK mais grade insuffisant pour execution");
	try
	{
		std::cout << signer << std::endl;
		std::cout << executor << std::endl;
		std::cout << form << std::endl;
		form.beSigned(signer);
		executor.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cout << "Erreur : " << e.what() << std::endl;
	}
}

void	test_full_execution(Bureaucrat& executor, AForm& f1, AForm& f2, AForm& f3)
{
	print_separator("Test: Signature et execution avec bureaucrate qualifié");
	try
	{
		f1.beSigned(executor);
		f2.beSigned(executor);
		f3.beSigned(executor);
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;

		print_separator("Execution de ShrubberyCreationForm");
		executor.executeForm(f1);

		print_separator("Execution de RobotomyRequestForm");
		executor.executeForm(f2);

		print_separator("Execution de PresidentialPardonForm");
		executor.executeForm(f3);
	}
	catch (const std::exception &e)
	{
		std::cout << "Erreur : " << e.what() << std::endl;
	}
}

int	main(void)
{
	ShrubberyCreationForm	shrubbery("Home");
	RobotomyRequestForm		robotomy("Morty");
	PresidentialPardonForm	pardon("Rick Sanchez");

	Bureaucrat mike("Mike", 150);
	Bureaucrat jon("Jon", 120);
	Bureaucrat steve("Steve", 3);

	test_execution_without_signature(mike, shrubbery, robotomy, pardon);
	test_signature_without_exec_rights(jon, mike, shrubbery);
	test_full_execution(steve, shrubbery, robotomy, pardon);

	return (0);
}