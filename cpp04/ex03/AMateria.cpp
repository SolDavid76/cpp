/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:02:15 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/18 16:54:18 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << "[AMateria]: Default constructor called" << std::endl;
	this->_type = "#DEFAULT#";
}

AMateria::AMateria(std::string const& type)
{
	std::cout << "[AMateria]: Parameter constructor called" << std::endl;
	this->_type = type;
}

AMateria::AMateria(const AMateria& src)
{
	std::cout << "[AMateria]: Copy constructor called" << std::endl;
	*this = src;
}

AMateria& AMateria::operator=(AMateria const& src)
{
	std::cout << "[AMateria]: Copy assignment constructor called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "[AMateria]: Destructor called" << std::endl;
}

std::string const& AMateria::get_type(void) const
{
	return (this->_type);
}
