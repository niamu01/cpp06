/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:29:39 by yeju              #+#    #+#             */
/*   Updated: 2022/04/11 14:38:40 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() : _input("")
{
}

Convert::Convert(std::string input) : _input(input)
{
	//input이 비어있는지 try-catch
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
	//*(const_cast<std::string*>(&_input)) = rhs.getInput();
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
		{
			std::cout << RED;
			std::cout << "Do not process non-displayable char." << std::endl;
			std::cout << RESET;
			return (false);
		}
		return (true);
	}
	return (false);
}

bool Convert::checkInt()
{
	std::string input = this->getInput();
	
	size_t i = 0;
	if (input.c_str()[i] == '+' || input.c_str()[i] == '-') //while?
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
	if (input.c_str()[input.length() - 1] != 'f') //가장 끝에 f가 없으면 false (f가 없는 소수점은 double)
		return (false);
	while (i < input.length()) //ex)1.3f
	{
		if (input.c_str()[i] == '.' && isdigit(input.c_str()[i + 1])) //.으로 끝나지 않으면서 .을 포함한 숫자가 소수점float이다.
		{
			i++;
			dot++;
		}
		else if (isdigit(input.c_str()[i]) || (input.c_str()[i] == 'f' && input.c_str()[i + 1] == '\0')) //f로 끝나거나 숫자면 i++해서 다음 자리 확인
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
		if (input.c_str()[i] == '.' && isdigit(input.c_str()[i + 1])) //.으로 끝나지 않으면 된다
		{
			i++;
			dot++;
		}
		else if (isdigit(input.c_str()[i]))
			i++;
		else
			return (false);
	}
	if (dot == 1) //.이 있어야댐 없으면 int니까..
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
	else if (input.length() == 1 && !isdigit(input.c_str()[0])) //1글자인데 숫자가 아니면
	{
		if (!isprint(input.c_str()[0]))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << static_cast<char>(input.c_str()[0]) << std::endl; //단순출력
	}
	else //2글자 이상이거나 숫자이면 (영어 2글자이상은 check에서 거름)
	{
		char *pEnd = NULL;
		double changeInput = strtod(input.c_str(), &pEnd);
		if (!isprint(static_cast<char>(changeInput)))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << static_cast<char>(changeInput) << std::endl; //단순출력
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
	else if (input.length() == 1 && !isdigit(input.c_str()[0])) //2글자 이상인데 시작이 숫자가 아니면 -가 붙었단 뜻이니까
		std::cout << static_cast<int>(input.c_str()[0]) << std::endl;
	else
	{
		char *pEnd = NULL;
		double changeInput = strtod(input.c_str(), &pEnd);
	// if ()
		// std::cout << "impossible" << std::endl;
	// else
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