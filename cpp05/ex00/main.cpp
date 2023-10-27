/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 00:17:07 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/27 00:26:29 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main(void)
{
	try
	{
		Bureaucrat bob("Bob", 1);
		// Bureaucrat bob("Bob", 250);

		std::cout << bob << std::endl;

		bob.promote();
		// bob.demote();
	}
	catch (std::exception const& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}
