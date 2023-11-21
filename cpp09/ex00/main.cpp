/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:36:59 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/21 12:14:13 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
	try
	{
		if (ac != 2)
			throw ft_exception("please use like this -> ./btc [file]");
		std::map<std::string, float> data = readDataBase("data.csv", ",");
		std::ifstream input(av[1]);
		std::string line;
		if (!input.is_open())
			throw ft_exception("Cannot open the file (" + std::string(av[1]) + ")");
		std::getline(input, line);
		while (std::getline(input, line))
		{
			try
			{
				bitcoinCalc(data, line);
			}
			catch (std::exception& e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
	}
	catch (std::exception const& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	(void)ac;
}
