#include "./include/Bureaucrat.hpp"
#include "./include/Form.hpp"
#include <iostream>

int	main(void)
{
	try
	{
		Bureaucrat b1("Alice", 50);
		Bureaucrat b2("Bob", 120);

		Form f1("FormA", 100, 50);
		Form f2("FormB", 140, 80);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;

		b1.signForm(f1);
		b2.signForm(f1);
		b2.signForm(f2);

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
