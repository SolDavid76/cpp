/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:11:02 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/03 13:02:22 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string input): _input(input)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const& src)
{
	*this = src;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& src)
{
	if (this != &src)
		this->_input = src._input;
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

bool isInt(std::string input)
{
	for (long unsigned int i = (input.at(0) == '-' ? 1 : 0); i < input.length(); i++)
	{
		if (!isdigit(input.at(i)))
			return (false);
	}
	return (true);
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
}

bool isIrrational(double input)
{
	if (std::isnan(input) || std::isinf(input))
		return (true);
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

void printChar(char c)
{
	if (32 <= c && c <= 126)
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void printInt(long int nbr)
{
	if (std::numeric_limits<int>::min() <= nbr && nbr <= std::numeric_limits<int>::max())
		std::cout << "int: " << nbr << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void printIrrational(double nbr)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << (nbr > 0 ? "+" : "") << nbr << "f" << std::endl;
	std::cout << "double: " << (nbr > 0 ? "+" : "") <<nbr << std::endl;
}

void printFloat(double nbr)
{if (-std::numeric_limits<float>::max() <= nbr && nbr <= std::numeric_limits<float>::max())
		std::cout << "float: " << nbr << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
}

void printDouble(long double nbr)
{if (-std::numeric_limits<double>::max() <= nbr && nbr <= std::numeric_limits<double>::max())
		std::cout << "double: " << nbr << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(void)
{
	switch (get_type(this->_input))
	{
		case (_char):
		{
			char tmp = this->_input.at(0);
			printChar(tmp);
			printInt(static_cast<int>(tmp));
			printFloat(static_cast<float>(tmp));
			printDouble(static_cast<double>(tmp));
			break;
		}
		case (_int):
		{
			long double tmp = atof(this->_input.c_str());
			printChar(static_cast<char>(tmp));
			printInt(static_cast<long int>(tmp));
			printFloat(static_cast<double>(tmp));
			printDouble(tmp);
			break;
		}
		case (_float):
		{
			long double tmp = atof(this->_input.c_str());
			if (isIrrational(tmp))
				printIrrational(tmp);
			else
			{
				printChar(static_cast<char>(tmp));
				printInt(static_cast<long int>(tmp));
				printFloat(static_cast<double>(tmp));
				printDouble(tmp);
			}
			break;
		}
		case (_double):
		{
			long double tmp = atof(this->_input.c_str());
			if (isIrrational(tmp))
				printIrrational(tmp);
			else
			{
				printChar(static_cast<char>(tmp));
				printInt(static_cast<long int>(tmp));
				printFloat(static_cast<double>(tmp));
				printDouble(tmp);
			}
			break;
		}
		default:
			std::cout << "Something went wrong" << std::endl;
	}
}
