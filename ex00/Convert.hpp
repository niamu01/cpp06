/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:11:55 by yeju              #+#    #+#             */
/*   Updated: 2022/04/11 20:26:18 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <iomanip>

# define RESET	"\033[0m"
# define RED	"\033[31m"

class Convert
{
private:
	std::string _input;
	
public:
	Convert();
	Convert(std::string input);
	Convert(Convert const &src);
	~Convert();
	
	Convert &operator=(Convert const &rhs);

	std::string getInput();

	bool inputError();

	bool checkInputType();
	
	bool checkChar();
	bool checkInt();
	bool checkFloat();
	bool checkDouble();

	void toChar();
	void toInt();
	void toFloat();
	void toDouble();

	
};

// std::ostream& operator<<(std::ostream& out, const Convert& convert);

#endif