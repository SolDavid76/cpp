/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:44:03 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/04 16:50:54 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	return (0);
}

// int main(void)
// {
// 	Fixed x(42.42f);
// 	Fixed y(10);

// 	std::cout << "x = " << x << "; y = " << y << std::endl;

// 	std::cout << "[COMPARISON OPERATORS]" << std::endl;
// 	std::cout << "(" << x << " < " << y << ") = " << std::boolalpha << (x < y) << std::noboolalpha << std::endl;
// 	std::cout << "(" << x << " < " << x << ") = " << std::boolalpha << (x < x) << std::noboolalpha << std::endl;
// 	std::cout << "(" << y << " < " << x << ") = " << std::boolalpha << (y < x) << std::noboolalpha << std::endl;
// 	std::cout << "(" << y << " < " << y << ") = " << std::boolalpha << (y < y) << std::noboolalpha << std::endl;

// 	std::cout << "(" << x << " > " << y << ") = " << std::boolalpha << (x > y) << std::noboolalpha << std::endl;
// 	std::cout << "(" << x << " > " << x << ") = " << std::boolalpha << (x > x) << std::noboolalpha << std::endl;
// 	std::cout << "(" << y << " > " << x << ") = " << std::boolalpha << (y > x) << std::noboolalpha << std::endl;
// 	std::cout << "(" << y << " > " << y << ") = " << std::boolalpha << (y > y) << std::noboolalpha << std::endl;

// 	std::cout << "(" << x << " <= " << y << ") = " << std::boolalpha << (x <= y) << std::noboolalpha << std::endl;
// 	std::cout << "(" << x << " <= " << x << ") = " << std::boolalpha << (x <= x) << std::noboolalpha << std::endl;
// 	std::cout << "(" << y << " <= " << x << ") = " << std::boolalpha << (y <= x) << std::noboolalpha << std::endl;
// 	std::cout << "(" << y << " <= " << y << ") = " << std::boolalpha << (y <= y) << std::noboolalpha << std::endl;

// 	std::cout << "(" << x << " >= " << y << ") = " << std::boolalpha << (x >= y) << std::noboolalpha << std::endl;
// 	std::cout << "(" << x << " >= " << x << ") = " << std::boolalpha << (x >= x) << std::noboolalpha << std::endl;
// 	std::cout << "(" << y << " >= " << x << ") = " << std::boolalpha << (y >= x) << std::noboolalpha << std::endl;
// 	std::cout << "(" << y << " >= " << y << ") = " << std::boolalpha << (y >= y) << std::noboolalpha << std::endl;

// 	std::cout << "(" << x << " == " << y << ") = " << std::boolalpha << (x == y) << std::noboolalpha << std::endl;
// 	std::cout << "(" << x << " == " << x << ") = " << std::boolalpha << (x == x) << std::noboolalpha << std::endl;
// 	std::cout << "(" << y << " == " << x << ") = " << std::boolalpha << (y == x) << std::noboolalpha << std::endl;
// 	std::cout << "(" << y << " == " << y << ") = " << std::boolalpha << (y == y) << std::noboolalpha << std::endl;

// 	std::cout << "(" << x << " != " << y << ") = " << std::boolalpha << (x != y) << std::noboolalpha << std::endl;
// 	std::cout << "(" << x << " != " << x << ") = " << std::boolalpha << (x != x) << std::noboolalpha << std::endl;
// 	std::cout << "(" << y << " != " << x << ") = " << std::boolalpha << (y != x) << std::noboolalpha << std::endl;
// 	std::cout << "(" << y << " != " << y << ") = " << std::boolalpha << (y != y) << std::noboolalpha << std::endl;

// 	return (0);
// }
