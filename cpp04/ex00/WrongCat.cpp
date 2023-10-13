/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:09 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/13 19:12:29 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "[WrongCat]: Default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src)
{
	std::cout << "[WrongCat]: Copy constructor called" << std::endl;
	*this = src;
}

WrongCat& WrongCat::operator=(WrongCat const& src)
{
	std::cout << "[WrongCat]: Copy assignement WrongCat operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "[WrongCat]: Destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "[WrongCat]: mooooooo" << std::endl;
}

