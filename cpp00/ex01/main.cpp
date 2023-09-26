/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:56:18 by djanusz           #+#    #+#             */
/*   Updated: 2023/09/26 11:38:24 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

std::string	ft_getline(std::string promt)
{
	std::string	res;

	while (!std::cin.eof() && res.empty())
	{
		std::cout << promt;
		std::getline(std::cin, res);
	}
	return (res);
}

void	Contact::fill_infos(void)
{
	this->_firstname = ft_getline("First name : ");
	this->_lastname = ft_getline("Last name : ");
	this->_nickname = ft_getline("Nickname : ");
	this->_phone = ft_getline("Phone number : ");
	this->_secret = ft_getline("Darkest secret : ");
}

void	PhoneBook::add(void)
{
	if (nbcontact < 8)
		this->_contactlist[nbcontact++].fill_infos();
	else
	{
		for(int i = 0; i < 7; i++)
			this->_contactlist[i] = this->_contactlist[i + 1];
		this->_contactlist[7].fill_infos();
	}
	return;
}

std::string	conform(std::string str)
{
	std::string	res;

	if (str.length() > 10)
	{
		res = str.substr(0, 9);
		res += ".";
		return (res);
	}
	return (str);
}

int	ft_stoi(std::string str)
{
	int res = 0;
	if (str.length() == 1 && '1' <= str[0] && str[0] <= '8')
		res = str[0] - 48;
	return (res - 1);
}

void	PhoneBook::search(void)
{
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│     Index│First name│ Last name│  Nickname│" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "│" << std::setw(10) << i + 1;
		std::cout << "│" << std::setw(10) << conform(this->_contactlist[i].get_firstname());
		std::cout << "│" << std::setw(10) << conform(this->_contactlist[i].get_lastname());
		std::cout << "│" << std::setw(10) << conform(this->_contactlist[i].get_nickname());
		std::cout << "│" << std::endl;
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
	int	input = ft_stoi(ft_getline("[1-8]: "));
	if (!std::cin.eof() &&  0 <= input && input <= 7)
	{
		std::cout << "First name: " << this->_contactlist[input].get_firstname() << std::endl;
		std::cout << "Last name: " << this->_contactlist[input].get_lastname() << std::endl;
		std::cout << "Nickname: " << this->_contactlist[input].get_nickname() << std::endl;
		std::cout << "Phone number: " << this->_contactlist[input].get_phone() << std::endl;
		std::cout << "Darkest secret: " << this->_contactlist[input].get_secret() << std::endl;
	}
	else
		std::cout << "[ERROR]: Wrong input" << std::endl;
	return;
}

int	PhoneBook::nbcontact = 0;

int	main(void)
{
	PhoneBook	book;
	std::string	input;

	while (42)
	{
		input = ft_getline("[ADD/SEARCH/EXIT]: ");
		if (!std::cin.eof() && input == "ADD")
			book.add();
		else if (!std::cin.eof() && input == "SEARCH")
			book.search();
		if (std::cin.eof() || input == "EXIT")
			return (0);
	}
}
