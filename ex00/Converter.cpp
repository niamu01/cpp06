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
/*
private:
	std::string _input;
	
public:
	Convert();
	Convert(std::string input);
	Convert(Convert const &src);
	~Convert();
	
	Convert &operator=(Convert const &rhs);

	std::string getInput();

	bool checkError();

	bool checkInputType();
	
	bool checkChar();
	bool checkInt();
	bool checkFloat();
	bool checkDouble();

	void toChar();
	void toInt();
	void toFloat();
	void toDouble();
*/


Convert::Convert() : _input("")
{
}

Convert::Convert(std::string input) : _input(input)
{
	std::cout << "Convert: Default constructor called" << std::endl;
	//input이 비어있는지 try-catch
}

Convert::Convert(const Convert &rhs) : _input(rhs.getInput())
{
	std::cout << "Convert: Copy constructor called" << std::endl;
}

Convert::~Convert()
{
	std::cout << "Convert: Destructor called" << std::endl;
}

Convert &Convert::operator=(Convert const &rhs)
{
	std::cout << "Convert: Assignement operator called" << std::endl;
	this->_input = rhs._input;
	//*(const_cast<std::string*>(&_input)) = rhs.getInput();
	return (*this);
}

std::string Convert::getInput()
{
	return (this->_input);
}

//-----------------check------------------

bool Convert::checkInputType()
{
	std::string input = this->getInput();

	if (input.length() == 0)
		throw Convert::EmptyInput();
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
		//print되는게 없을시 검사하기를 다른 방법 찾아보기
		if (!isprint(input.c_str()[0]))
		{
			std::cout << RED << "Do not process non-displayable char." << RESET << std::endl;
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
	//연속의 기호가 들어오면?
	if (input.c_str()[i] == '+' || input.c_str()[i] == '-')
		i++;
	while (i < input.length())
	{
		//isdigit함수...
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
	size_t count = 0;
	if (input.c_str()[i] == '+' || input.c_str()[i] == '-')
		i++;
	if (input.c_str()[input.length() - 1] != 'f')
		return (false);
	while (i < input.length())
	{
		if (input.c_str()[i] == '.' && isdigit(input.c_str()[i + 1]))
		{
			i++;
			count++;
		}
		else if (isdigit(input.c_str()[i]) || (input.c_str()[i] == 'f' && input.c_str()[i + 1] == '\0'))
			i++;
		else
			return (false);
	}
	if (count == 1)
		return (true);
	return (false);
}

bool Convert::checkDouble()
{

	std::string input = this->getInput();

	if (this->getInput() == "-inf" || this->getInput() == "+inf" || this->getInput() == "nan")
		return (true);

	size_t i = 0;
	size_t count = 0;
	if (input.c_str()[i] == '+' || input.c_str()[i] == '-')
		i++;
	while (i < input.length())
	{
		if (input.c_str()[i] == '.' && isdigit(input.c_str()[i + 1]))
		{
			i++;
			count++;
		}
		else if (isdigit(input.c_str()[i]))
			i++;
		else
			return (false);
	}
	if (count == 1)
		return (true);
	return (false);
}

//-----------------convert to------------------

void Convert::toChar()
{

	std::cout << "char: ";

}

void Convert::toInt()
{
	std::cout << "int: ";

}

void Convert::toFloat()
{
	std::cout << "float: ";

}

void Convert::toDouble()
{
	std::cout << "double: ";

	
}