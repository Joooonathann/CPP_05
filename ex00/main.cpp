#include "./include/Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    {
        try
        {
            Bureaucrat test("Jonathan", 1);
            std::cout << test << std::endl;
            test.upGrade();
            std::cout << test << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        try
        {
            Bureaucrat test("Jonathan", 150);
            std::cout << test << std::endl;
            test.upGrade();
            std::cout << test << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        try
        {
            Bureaucrat test("Jonathan", 0);
            std::cout << test << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    

    {
        try
        {
            Bureaucrat test("Jonathan", 151);
            std::cout << test << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return (0);
}