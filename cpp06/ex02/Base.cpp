/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:35:10 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/29 17:03:08 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* generate(void)
{
	std::srand(time(NULL));
	switch (std::rand() % 3)
	{
		case (0):
			return (new A);
		case (1):
			return (new B);
		case (2):
			return (new C);
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type is C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& x = dynamic_cast<A&>(p);
		std::cout << "Type is A" << std::endl;
		(void)x;
	}
	catch (std::exception const& e) {}
	try
	{
		B& x = dynamic_cast<B&>(p);
		std::cout << "Type is B" << std::endl;
		(void)x;
	}
	catch (std::exception const& e) {}
	try
	{
		C& x = dynamic_cast<C&>(p);
		std::cout << "Type is C" << std::endl;
		(void)x;
	}
	catch (std::exception const& e) {}
}
