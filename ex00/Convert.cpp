/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:11:47 by yeju              #+#    #+#             */
/*   Updated: 2022/04/11 20:29:18 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() : _input("")
{
}

Convert::Convert(std::string input) : _input(input)
{
}

Convert::Convert(Convert const &rhs)
{
	*this = rhs;
}

Convert::~Convert()
{
}

Convert &Convert::operator=(Convert const &rhs)
{
	this->_input = rhs._input;
	return (*this);
}

std::string Convert::getInput()
{
	return (this->_input);
}

bool Convert::checkInputType()
{
	std::string input = this->getInput();

	if (input.length() == 0)
		return (false);
	if (this->checkChar() || this->checkInt() || this->checkFloat() || this->checkDouble())
		return (true);
	else
		return (false);
}

bool Convert::checkChar()
{
	std::string input = this->getInput();

	if (input.length() == 1)
	{
		if (!isprint(input.c_str()[0]))
			return (false);
		return (true);
	}
	return (false);
}

bool Convert::checkInt()
{
	std::string input = this->getInput();
	
	size_t i = 0;
	if (input.c_str()[i] == '+' || input.c_str()[i] == '-')
		i++;
	while (i < input.length())
	{
		if (isdigit(input.c_str()[i]))
			i++;
		else
			return (false);
	}
	return (true);
}

bool Convert::checkFloat()
{
	std::string input = this->getInput();

	if (this->getInput() == "-inff" || this->getInput() == "+inff" || this->getInput() == "nanf")
		return (true);

	size_t i = 0;
	size_t dot = 0;

	if (input.c_str()[i] == '+' || input.c_str()[i] == '-')
		i++;
	if (input.c_str()[input.length() - 1] != 'f')
		return (false);
	while (i < input.length())
	{
		if (input.c_str()[i] == '.' && isdigit(input.c_str()[i + 1]))
		{
			i++;
			dot++;
		}
		else if (isdigit(input.c_str()[i]) || (input.c_str()[i] == 'f' && input.c_str()[i + 1] == '\0'))
			i++;
		else
			return (false);
	}
	if (dot == 1)
		return (true);
	return (false);
}

bool Convert::checkDouble()
{
	std::string input = this->getInput();

	if (this->getInput() == "-inf" || this->getInput() == "+inf" || this->getInput() == "nan")
		return (true);

	size_t i = 0;
	size_t dot = 0;
	
	if (input.c_str()[i] == '+' || input.c_str()[i] == '-')
		i++;
	while (i < input.length())
	{
		if (input.c_str()[i] == '.' && isdigit(input.c_str()[i + 1]))
		{
			i++;
			dot++;
		}
		else if (isdigit(input.c_str()[i]))
			i++;
		else
			return (false);
	}
	if (dot == 1)
		return (true);
	return (false);
}

void Convert::toChar()
{
	std::cout << "char: ";

	std::string input = this->getInput();

	if (input == "-inf" || input == "+inf" || input == "nan")
		std::cout << "impossible" << std::endl;
	else if (input == "-inff" || input == "+inff" || input == "nanf")
		std::cout << "impossible" << std::endl;
	else if (input.length() == 1 && !isdigit(input.c_str()[0]))
	{
		if (!isprint(input.c_str()[0]))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << static_cast<char>(input.c_str()[0]) << std::endl;
	}
	else
	{
		char *pEnd = NULL;
		double changeInput = strtod(input.c_str(), &pEnd);
		if (!isprint(static_cast<char>(changeInput)))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << static_cast<char>(changeInput) << std::endl;
	}
}

void Convert::toInt()
{
	std::cout << "int: ";

	std::string input = this->getInput();

	if (input == "-inf" || input == "+inf" || input == "nan")
		std::cout << "impossible" << std::endl;
	else if (input == "-inff" || input == "+inff" || input == "nanf")
		std::cout << "impossible" << std::endl;
	else if (input.length() == 1 && !isdigit(input.c_str()[0]))
		std::cout << static_cast<int>(input.c_str()[0]) << std::endl;
	else
	{
		char *pEnd = NULL;
		double changeInput = strtod(input.c_str(), &pEnd);
		std::cout << static_cast<int>(changeInput) << std::endl;
	}
}

void Convert::toFloat()
{
	std::cout << "float: ";

	std::string input = this->getInput();

	if (input == "-inf" || input == "+inf" || input == "nan")
		std::cout << input << "f" << std::endl;
	else if (input == "-inff" || input == "+inff" || input == "nanf")
		std::cout << input << std::endl;
	else if (input.length() == 1 && !isdigit(input.c_str()[0]))
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(input.c_str()[0]) << "f" << std::endl;
	else
	{
		char *pEnd = NULL;
		double changeInput = strtod(input.c_str(), &pEnd);
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(changeInput) << "f" << std::endl;
	}
}

void Convert::toDouble()
{
	std::cout << "double: ";

	std::string input = this->getInput();

	if (input == "-inf" || input == "+inf" || input == "nan")
		std::cout << input << std::endl;
	else if (input == "-inff" || input == "+inff" || input == "nanf")
		std::cout << input.substr(0, input.length() - 1) << std::endl;
	else if (input.length() == 1 && !isdigit(input.c_str()[0]))
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(input.c_str()[0]) << std::endl;
	else
	{
		char *pEnd = NULL;
		double changeInput = strtod(input.c_str(), &pEnd);
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(changeInput) << std::endl;
	}
}