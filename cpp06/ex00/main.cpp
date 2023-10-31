/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:02:56 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/27 16:23:41 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Wrong number of args!" << std::endl;
		return (-1);
	}
	ScalarConverter input(av[1]);
	input.convert();
}