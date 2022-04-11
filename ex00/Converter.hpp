/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:27:59 by yeju              #+#    #+#             */
/*   Updated: 2022/04/11 14:35:54 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
//#include <cerrno>
//#include <limits>
#include <iomanip>
//#include <cfloat>

//#define PRECISION 1
//#define FLT_MIN -3.40282e+38
//#define FLT_MAX 3.40282e+38

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

	
};

std::ostream& operator<<(std::ostream& out, const Convert& convert);

#endif