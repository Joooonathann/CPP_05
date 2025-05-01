#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm::AForm("ShrubberyCreationForm", 25, 5), _target("null") { }

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm::AForm("ShrubberyCreationForm", 25, 5), _target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy): AForm::AForm(copy), _target(copy._target) { }

ShrubberyCreationForm::~ShrubberyCreationForm(void) { }

ShrubberyCreationForm const	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

void ShrubberyCreationForm::executed(void) const
{
	std::ofstream	outfile;

	outfile.open((this->_target + "_shrubbery").c_str());
	if (outfile.fail())
	{
		std::cout << "Error: could not open output file." << std::endl;
		return ;
	}
	outfile << 
	"               ###\n"
	"              #o###\n"
	"            #####o###\n"
	"           #o#\\#|#/###\n"
	"            ###\\|/#o#\n"
	"             # }|{  #\n"
	"               }|{\n"
	"             /\\|||/\\\n"
	"            /_|||||_\\\n"
	"               |||\n"
	"               |||\n"
	"               |||\n"
	"              /|||\\\n"
	"             //|||\\\\\n"
	"            ///|||\\\\\\\n";
	outfile.close();
}
