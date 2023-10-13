/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:44:16 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/13 19:11:33 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "[Cat]: Default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& src)
{
	std::cout << "[Cat]: Copy constructor called" << std::endl;
	*this = src;
}

Cat& Cat::operator=(Cat const& src)
{
	std::cout << "[Cat]: Copy assignement Cat operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "[Cat]: Destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "[Cat]: meowww" << std::endl;
}
