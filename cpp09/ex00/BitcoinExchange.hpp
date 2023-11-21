/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:37:29 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/21 12:15:58 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <regex.h>

# include <map>
# include <limits>
# include <string>
# include <cstring>
# include <sstream>
# include <fstream>
# include <iostream>
# include <cstdlib>

class ft_exception: public std::exception
{
	public:
		ft_exception(std::string errorMessage) throw(): _errorMessage(errorMessage) {}
		virtual const char* what() const throw() { return (this->_errorMessage.c_str()); }
		virtual ~ft_exception() throw() {}
	private:
		std::string _errorMessage;
};

/* BitcoinExchange.cpp */
const char* get_regex(std::string path);
bool pars_date(int year, int month, int day);
void pars_line(std::string path, std::string line);
std::map<std::string, float> readDataBase(std::string path, std::string delimiter);
void bitcoinCalc(std::map<std::string, float> data, std::string line);

#endif
