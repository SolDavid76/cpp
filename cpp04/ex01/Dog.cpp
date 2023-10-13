/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:13:56 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/13 19:11:39 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "[Dog]: Default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog& src)
{
	std::cout << "[Dog]: Copy constructor called" << std::endl;
	*this = src;
}

Dog& Dog::operator=(Dog const& src)
{
	std::cout << "[Dog]: Copy assignement Dog operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "[Dog]: Destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "[Dog]: bark" << std::endl;
}

