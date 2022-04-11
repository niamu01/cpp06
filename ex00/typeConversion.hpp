
#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cerrno>
#include <limits>
#include <iomanip>
#include <cfloat>

#define PRECISION 1
#define FLT_MIN -3.40282e+38
#define FLT_MAX 3.40282e+38

# define RESET			"\033[0m"
# define RED			"\033[31m"				/* Red */


class typeConversion {

private:
	std::string _input;

public:
	explicit typeConversion(std::string input="");
	~typeConversion();
	typeConversion(typeConversion const & src);
	typeConversion & operator=(typeConversion const & rhs);

	std::string getInput();

	// input check
	bool checkChar();
	bool checkInt();
	bool checkFloat();
	bool checkDouble();
	bool checkInputType();

	// input convert
	void convertToChar();
	void convertToInt();
	void convertToFloat();
	void convertToDouble();
};
