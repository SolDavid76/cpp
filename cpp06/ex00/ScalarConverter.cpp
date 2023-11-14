/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:11:02 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/14 16:36:13 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	this->_c = 0;
	this->_i = 0;
	this->_f = 0;
	this->_d = 0;
}

ScalarConverter::ScalarConverter(ScalarConverter const& src)
{
	*this = src;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& src)
{
	if (this != &src)
	{
		this->_c = src._c;
		this->_i = src._i;
		this->_f = src._f;
		this->_d = src._d;
	}
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

bool isChar(std::string input)
{
	if (input.length() == 1 && !isdigit(input.at(0)))
		return (true);
	return (false);
}

bool checkInt(std::string str)
{
	unsigned long int s = 0;
	
	if (str[0] == '-' || str[0] == '+')
		s = 1;
	if (str.length() == 10 + s)
	{
		if (str[0 + s] != '2' )
			return (str[0 + s] < '2');
		if (str[1 + s] != '1' )
			return (str[1 + s] < '1');
		if (str[2 + s] != '4' )
			return (str[2 + s] < '4');
		if (str[3 + s] != '7' )
			return (str[3 + s] < '7');
		if (str[4 + s] != '4' )
			return (str[4 + s] < '4');
		if (str[5 + s] != '8' )
			return (str[5 + s] < '8');
		if (str[6 + s] != '3' )
			return (str[6 + s] < '3');
		if (str[7 + s] != '6' )
			return (str[7 + s] < '6');
		if (str[8 + s] != '4' )
			return (str[8 + s] < '4');
		if ((str[0] == '-' && str[9 + s] != '8') || (str[0] != '-' && str[9 + s] != '7'))
			return (str[0] == '-' ? str[9 + s] < '8' : str[9 + s] < '7');
	}
	return (true);
}

bool isInt(std::string input)
{
	if (!checkInt(input))
		return (false);
	for (long unsigned int i = (input.at(0) == '-' ? 1 : 0); i < input.length(); i++)
	{
		if (!isdigit(input.at(i)))
			return (false);
	}
	return (true);
}

bool isIrrational(double input)
{
	if (std::isnan(input) || std::isinf(input))
		return (true);
	return (false);
}

bool isFloat(std::string input)
{
	bool found_point = false;

	if (input.at(input.length() - 1) != 'f')
		return (false);
	if (input == "nanf" || input == "+inff" || input == "-inff")
		return (true);
	for (long unsigned int i = (input.at(0) == '-' ? 1 : 0); i < input.length() - 1; i++)
	{
		if (input.at(i) == '.')
		{
			if (found_point)
				return (false);
			found_point = true;
		}
		else if (!isdigit(input.at(i)))
			return (false);
	}
	if (input.find_first_of("0123456789", 0) == std::string::npos || input[input.length() - 2] == '.')
		return (false);
	return (true);
}

bool isDouble(std::string input)
{
	bool found_point = false;

	if (input == "nan" || input == "+inf" || input == "-inf")
		return (true);
	for (long unsigned int i = (input.at(0) == '-' ? 1 : 0); i < input.length(); i++)
	{
		if (input.at(i) == '.')
		{
			if (found_point)
				return (false);
			found_point = true;
		}
		else if (!isdigit(input.at(i)))
			return (false);
	}
	return (true);
	if (input.find_first_of("0123456789", 0) == std::string::npos || input[input.length() - 1] == '.')
		return (false);
}

e_type get_type(std::string input)
{
	if (isChar(input))
		return (_char);
	if (isInt(input))
		return (_int);
	if (isFloat(input))
		return (_float);
	if (isDouble(input))
		return (_double);
	return (_error);
}

void ScalarConverter::printChar(void)
{
	if (32 <= this->_c && this->_c <= 126)
		std::cout << "char: '" << this->_c << "'" << std::endl;
	else if ((this->_i >= 0 && this->_i < 32) || this->_i == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

void ScalarConverter::printInt(void)
{
	if (std::numeric_limits<int>::min() <= this->_i && this->_i <= std::numeric_limits<int>::max())
		std::cout << "int: " << this->_i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void ScalarConverter::printIrrational(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << (this->_f > 0 ? "+" : "") << this->_f << "f" << std::endl;
	std::cout << "double: " << (this->_d > 0 ? "+" : "") << this->_d << std::endl;
}

void ScalarConverter::printFloat(void)
{
	if (-std::numeric_limits<float>::max() <= this->_f && this->_f <= std::numeric_limits<float>::max())
		std::cout << "float: " << this->_f << (this->_f - static_cast<int>(this->_f) == 0 ? ".0f" : "f") << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
}

void ScalarConverter::printDouble(void)
{
	if (-std::numeric_limits<double>::max() <= this->_d && this->_d <= std::numeric_limits<double>::max())
		std::cout << "double: " << this->_d << (this->_d - static_cast<int>(this->_d) == 0 ? ".0" : "") << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::printAll(void)
{
	if (isIrrational(this->_f))
		this->printIrrational();
	else
	{
		this->printChar();
		this->printInt();
		this->printFloat();
		this->printDouble();
	}
}

void ScalarConverter::convert(std::string input)
{
	switch (get_type(input))
	{
		case (_char):
		{
			this->_c = input[0];
			this->_i = static_cast<int>(this->_c);
			this->_f = static_cast<float>(this->_c);
			this->_d = static_cast<double>(this->_c);
			this->printAll();
			break;
		}
		case (_int):
		{
			std::cout << "coucou" << std::endl;
			this->_i = atoi(input.c_str());
			this->_c = static_cast<char>(this->_i);
			this->_f = static_cast<float>(this->_i);
			this->_d = static_cast<double>(this->_i);
			this->printAll();
			break;
		}
		case (_float):
		{
			this->_f = atof(input.c_str());
			this->_c = static_cast<char>(this->_f);
			this->_i = (std::numeric_limits<int>::min() <= this->_f && this->_f <= std::numeric_limits<int>::max() ? static_cast<int>(this->_f) : 2147483648);
			this->_d = static_cast<double>(this->_f);
			this->printAll();
			break;
		}
		case (_double):
		{
			this->_d = atof(input.c_str());
			this->_c = static_cast<char>(this->_d);
			this->_i = (std::numeric_limits<int>::min() <= this->_d && this->_d <= std::numeric_limits<int>::max() ? static_cast<int>(this->_d) : 2147483648);
			this->_f = static_cast<float>(this->_d);
			this->printAll();
			break;
		}
		default:
			std::cout << "Something went wrong" << std::endl;
	}
}
