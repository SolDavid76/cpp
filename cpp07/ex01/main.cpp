/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:35:51 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/03 13:56:31 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int square(int x)
{
	return (x * x);
}

double square(double x)
{
	return (x * x);
}

int main(void)
{
	int intArray[7] = {0, 1, 2, 3, 4, 5 , 10};
	double doubleArray[7] = {0, 1, 2, 3, 4, 5 , 10};

	std::cout << "-----intArray-----" << std::endl;
	for (int i = 0; i < 7; i++)
		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
	iter(intArray, 7, square);
	std::cout << "-----intArray-----" << std::endl;
	for (int i = 0; i < 7; i++)
		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;

	std::cout << "-----doubleArray-----" << std::endl;
	for (int i = 0; i < 7; i++)
		std::cout << "doubleArray[" << i << "] = " << doubleArray[i] << std::endl;
	iter(doubleArray, 7, square);
	std::cout << "-----doubleArray-----" << std::endl;
	for (int i = 0; i < 7; i++)
		std::cout << "doubleArray[" << i << "] = " << doubleArray[i] << std::endl;
	return (0);
}