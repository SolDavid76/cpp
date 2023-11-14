/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:03:51 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/14 16:03:38 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <stdlib.h>
# include <limits>
# include <string>
# include <iostream>
# include <iomanip>
# include <cmath>

enum e_type {_error, _irrational, _char, _int, _float, _double};

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const& src);
		ScalarConverter& operator=(ScalarConverter const& src);
		~ScalarConverter(void);

		void printChar(void);
		void printInt(void);
		void printIrrational(void);
		void printFloat(void);
		void printDouble(void);
		void printAll(void);
		void convert(std::string input);
	private:
		char _c;
		long _i;
		float _f;
		double _d;
};

#endif
