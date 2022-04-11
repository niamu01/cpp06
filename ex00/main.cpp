
#include <iostream>
#include "Convert.hpp"

int main(int argc, char** argv)
{
	if (argc == 1)
		std::cout << RED << "Not enough argument." << RESET << std::endl;
	else if (argc > 2)
		std::cout << RED << "Too many arguments." << RESET << std::endl;
	else
	{
		Convert Convert(argv[1]);
		if (!Convert.checkInputType())
		{
			std::cout << RED << "Please enter one of the following scala types: char, int, float or double." << RESET << std::endl;
			return 0;
		}

		Convert.convertToChar();
		Convert.convertToInt();
		Convert.convertToFloat();
		Convert.convertToDouble();
	}
	return 0;
}

// ./convert 0
// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0
//
// ./convert nan
// char: impossible
// int: impossible
// float: nanf
// double: nan
//
// ./convert 42.0f
// char:'*'
// int: 42
// float: 42.0f
// double: 42.0

// ./convert ~
// char: ~
// int: 126
// float: 126.0f
// double: 126.0

