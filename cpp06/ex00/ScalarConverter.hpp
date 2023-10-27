/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:03:51 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/27 20:21:53 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <stdlib.h>
# include <limits>
# include <string>
# include <iostream>

enum e_type {_error, _irrational, _char, _int, _float, _double};

class ScalarConverter
{
	public:
		ScalarConverter(std::string input);
		ScalarConverter(ScalarConverter const& src);
		ScalarConverter& operator=(ScalarConverter const& src);
		~ScalarConverter(void);

		void convert(void);
	private:
		std::string _input;
};

#endif
