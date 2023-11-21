/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:37:15 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/21 12:14:20 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char* get_regex(std::string path)
{
	if (path.length() > 4 && path.substr(path.length() - 4) == ".csv")
		return ("[0-9]{4}-[0-9]{2}-[0-9]{2},[+-]?[0-9]*.?[0-9]+");
	else
		return ("[0-9]{4}-[0-9]{2}-[0-9]{2} | [+-]?[0-9]*.?[0-9]+");
}

bool pars_date(int year, int month, int day)
{
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
		return (false);
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			if (day > 29)
				return (false);
		}
		else
		{
			if (day > 28)
				return (false);
		}
	}
	return (true);
}

void pars_line(std::string path, std::string line)
{
	regex_t regex;

	regcomp(&regex, get_regex(path), REG_EXTENDED);
	if (regexec(&regex, line.c_str(), 0, NULL, 0))
	{
		regfree(&regex);
		throw ft_exception("bad input => " + line);
	}
	regfree(&regex);
	if (!pars_date(atoi(line.substr(0, 4).c_str()), atoi(line.substr(5, 2).c_str()), atoi(line.substr(8, 2).c_str())))
		throw ft_exception(line.substr(0, 10) + " is not in the calendar");
	if (atof(line.substr(line.find_first_of("|,") + 1).c_str()) < 0)
		throw ft_exception(line.substr(line.find_first_of("|,") + 2) + " is not a positive number");
}

std::map<std::string, float> readDataBase(std::string path, std::string delimiter)
{
	std::map<std::string, float> res;
	std::ifstream ifs(path.c_str());
	std::string line;

	if (!ifs.is_open())
		throw ft_exception("Cannot open the file (" + path + ")");
	std::getline(ifs, line);
	while (std::getline(ifs, line))
	{
		pars_line(path, line);
		res.insert(std::pair<std::string, float>(line.substr(0, line.find(delimiter)), atof(line.substr(line.find(delimiter) + 1).c_str())));
	}
	return (res);
}

void bitcoinCalc(std::map<std::string, float> data, std::string line)
{
	pars_line("", line);
	std::string date = line.substr(0, 10);
	std::string val = line.substr(13);
	if (atof(val.c_str()) > 1000)
		throw ft_exception(val + " is too large");
	std::map<std::string, float>::iterator it = data.find(date);
	if (it != data.end())
		std::cout << date << " => " << val << " = " << atof(val.c_str()) * it->second << std::endl;
	else
		std::cout << date << " => " << val << " = " << atof(val.c_str()) * data.lower_bound(date)->second << std::endl;
}
