/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:36:15 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/13 19:12:20 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "[WrongAnimal]: Default constructor called" << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	std::cout << "[WrongAnimal]: Copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& src)
{
	std::cout << "[WrongAnimal]: Copy assignement WrongAnimal operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "[WrongAnimal]: Destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "[WrongAnimal]: *Can't make wrong sound*" << std::endl;
}

std::string WrongAnimal::get_type(void) const
{
	return (this->_type);
}

