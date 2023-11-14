/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:02:56 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/14 16:11:48 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
	if (ac != 2 || !av[1][0])
	{
		std::cout << "Wrong number of args!" << std::endl;
		return (-1);
	}
	ScalarConverter input;
	input.convert(av[1]);
}
