/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:03:21 by yeju              #+#    #+#             */
/*   Updated: 2022/04/11 16:03:24 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

		Convert.toChar();
		Convert.toInt();
		Convert.toFloat();
		Convert.toDouble();
	}
	return 0;
}