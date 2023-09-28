/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:14:23 by djanusz           #+#    #+#             */
/*   Updated: 2023/09/28 15:14:23 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
	Harl bob;

	if (ac == 2)
		bob.complain(av[1]);
	else
		std::cout << "Wrong number of args" << std::endl;
}