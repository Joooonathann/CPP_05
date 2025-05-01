#include "./include/Bureaucrat.hpp"
#include "./include/AForm.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include "./include/Intern.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== Création des bureaucrates ===\n\n";

	Bureaucrat low("LowLevel", 150);
	Bureaucrat mid("MidLevel", 70);
	Bureaucrat high("HighLevel", 1);

	std::cout << low << std::endl;
	std::cout << mid << std::endl;
	std::cout << high << std::endl;

	std::cout << "\n=== Test de création de formulaires par le stagiaire ===\n\n";

	Intern intern;
	AForm* shrub = intern.makeForm("shrubbery creation", "Jardin");
	AForm* robot = intern.makeForm("robotomy request", "Bender");
	AForm* pardon = intern.makeForm("presidential pardon", "Rick");
	AForm* unknown = intern.makeForm("unknown form", "Nobody");

	std::cout << "\n=== Test de signature et exécution des formulaires ===\n\n";

	// Test avec LowLevel - trop faible
	std::cout << "\n-- LowLevel essaie de signer et exécuter --\n";
	try {
		if (shrub) shrub->beSigned(low);
		if (shrub) low.executeForm(*shrub);
	} catch (std::exception &e) {
		std::cout << "Erreur : " << e.what() << std::endl;
	}

	// Test avec MidLevel - peut signer shrubbery
	std::cout << "\n-- MidLevel essaie de signer et exécuter Shrubbery --\n";
	try {
		if (shrub) shrub->beSigned(mid);
		if (shrub) mid.executeForm(*shrub);
	} catch (std::exception &e) {
		std::cout << "Erreur : " << e.what() << std::endl;
	}

	// Test avec HighLevel - peut tout signer et exécuter
	std::cout << "\n-- HighLevel signe et exécute tout --\n";
	try {
		if (robot) robot->beSigned(high);
		if (pardon) pardon->beSigned(high);

		if (robot) high.executeForm(*robot);
		if (pardon) high.executeForm(*pardon);
	} catch (std::exception &e) {
		std::cout << "Erreur : " << e.what() << std::endl;
	}

	std::cout << "\n=== Nettoyage mémoire ===\n";

	delete shrub;
	delete robot;
	delete pardon;
	delete unknown;

	return 0;
}