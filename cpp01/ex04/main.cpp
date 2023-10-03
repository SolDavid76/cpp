/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:40:18 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/03 15:26:44 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void ft_replace(std::string file, std::string s1, std::string s2)
{
	std::ifstream ifs(file.c_str());
	std::ofstream ofs((file + ".replace").c_str());
	std::string str;
	unsigned long index;

	if (!ifs.is_open() || !ofs.is_open())
	{
		std::cout << "Cannot open the files" << std::endl;
		return;
	}
	getline(ifs, str, '\0');
	index = str.find(s1);
	while (index != std::string::npos)
	{
		str.erase(index, s1.length());
		str.insert(index, s2);
		index = str.find(s1, index + s2.length());
	}
	ofs << str;
}

int main(int ac, char** av)
{
	if (ac == 4 && av[2][0] && av[3][0])
		ft_replace(av[1], av[2], av[3]);
	else
		std::cout << "Wrong number of args" << std::endl;
}