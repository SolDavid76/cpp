/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:51:27 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/13 19:11:22 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "[Animal]: Default constructor called" << std::endl;
	this->_type = "Animal";
}

Animal::Animal(const Animal& src)
{
	std::cout << "[Animal]: Copy constructor called" << std::endl;
	*this = src;
}

Animal& Animal::operator=(Animal const& src)
{
	std::cout << "[Animal]: Copy assignement Animal operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "[Animal]: Destructor called" << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << "[Animal]: *Can't make sound*" << std::endl;
}

std::string Animal::get_type(void) const
{
	return (this->_type);
}
