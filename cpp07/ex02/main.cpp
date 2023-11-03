/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:12:21 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/03 16:06:56 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	Array<int> intArray(5);
	intArray[0] = 42;
	intArray[1] = 1;
	intArray[2] = -42;
	intArray[4] = 1;
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
	try
	{
		intArray[9] = 2;
	}
	catch (std::exception const& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}