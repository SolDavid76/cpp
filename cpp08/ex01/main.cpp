/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:31:27 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/08 16:42:21 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// int main(void)
// {
// 	Span x(10);
// 	x.addNumber(1);
// 	x.addNumber(5);
// 	x.addNumber(14);
// 	x.addNumber(42);
// 	x.addNumber(-9);
// 	std::cout << "[shortest distance in span] = " << x.shortestSpan() << std::endl;
// 	std::cout << "[longest distance in span] = " << x.longestSpan() << std::endl;
// 	return (0);
// }

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
