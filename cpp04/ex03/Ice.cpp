/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:51:58 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/18 16:15:30 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Character.hpp"

Ice::Ice(void)
{
	std::cout << "[Ice]: Default constructor called" << std::endl;
	this->_type = "ice";
}

Ice::Ice(const Ice& src)
{
	std::cout << "[Ice]: Copy constructor called" << std::endl;
	*this = src;
}

Ice& Ice::operator=(Ice const& src)
{
	std::cout << "[Ice]: Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << "[Ice]: Destructor called" << std::endl;
}

AMateria* Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "[Ice]: \"*shoots an ice bolt at " << target.get_name() <<  "*\"" << std::endl;
}
