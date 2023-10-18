/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:58:36 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/18 17:01:59 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Character.hpp"

Cure::Cure(void)
{
	std::cout << "[Cure]: Default constructor called" << std::endl;
	this->_type = "cure";
}

Cure::Cure(const Cure& src)
{
	std::cout << "[Cure]: Copy constructor called" << std::endl;
	*this = src;
}

Cure& Cure::operator=(Cure const& src)
{
	std::cout << "[Cure]: Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << "[Cure]: Destructor called" << std::endl;
}

AMateria* Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "[Cure]: \"*heals " << target.get_name() <<  "’s wounds*\"" << std::endl;
}
