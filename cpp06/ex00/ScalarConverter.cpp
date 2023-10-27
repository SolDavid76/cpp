/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:11:02 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/27 20:29:16 by djanusz          ###   ########.fr       */
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
	if (input.length() != 1 || input.at(0) < 0)
		return (false);
	return (true);
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

bool isIrrational(std::string input)
{
	if (input == "nanf" || input == "+inff" || input == "-inff" || input == "nan" || input == "+inf" || input == "-inf")
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
	std::cout << "input type was detected as char" << std::endl;
	if (32 <= c && c <= 126)
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void printInt(long int nbr)
{
	std::cout << "input type was detected as int" << std::endl;
	if (32 <= nbr && nbr <= 126)
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (std::numeric_limits<int>::min() <= nbr && nbr <= std::numeric_limits<int>::max())
		std::cout << "int: " << nbr << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (std::numeric_limits<float>::min() <= nbr && nbr <= std::numeric_limits<float>::max())
		std::cout << "float: " << static_cast<float>(nbr) << ".0f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	if (std::numeric_limits<double>::min() <= nbr && nbr <= std::numeric_limits<double>::max())
		std::cout << "double: " << static_cast<double>(nbr) << ".0" << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}

void printFloat(float nbr)
{
	std::cout << "input type was detected as float" << std::endl;
	if (32 <= nbr && nbr <= 126)
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (std::numeric_limits<int>::min() <= nbr && nbr <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (std::numeric_limits<float>::min() <= nbr && nbr <= std::numeric_limits<float>::max())
		std::cout << "float: " << nbr << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	if (std::numeric_limits<double>::min() <= nbr && nbr <= std::numeric_limits<double>::max())
		std::cout << "double: " << static_cast<double>(nbr) << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}

void printDouble(double nbr)
{
	std::cout << "input type was detected as double" << std::endl;
	if (32 <= nbr && nbr <= 126)
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (std::numeric_limits<int>::min() <= nbr && nbr <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (std::numeric_limits<float>::min() <= nbr && nbr <= std::numeric_limits<float>::max())
		std::cout << "float: " << static_cast<float>(nbr) << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	if (std::numeric_limits<double>::min() <= nbr && nbr <= std::numeric_limits<double>::max())
		std::cout << "double: " << nbr << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}

void printIrrational(std::string input, e_type type)
{
	if (type == _float)
		std::cout << "input type was detected as float" << std::endl;
	else
		std::cout << "input type was detected as double" << std::endl;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (type == _float)
	{
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
	}
	else
	{
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
	}
}

void ScalarConverter::convert(void)
{
	switch (get_type(this->_input))
	{
		case (_char):
			printChar(this->_input.at(0));
			break;
		case (_int):
			printInt(atol(this->_input.c_str()));
			break;
		case (_float):
			if (isIrrational(this->_input))
				printIrrational(this->_input, _float);
			else
				printFloat(atof(this->_input.c_str()));
			break;
		case (_double):
			if (isIrrational(this->_input))
				printIrrational(this->_input, _double);
			else
				printDouble(atof(this->_input.c_str()));
			break;
		default:
			std::cout << "Something went wrong" << std::endl;
	}
}
