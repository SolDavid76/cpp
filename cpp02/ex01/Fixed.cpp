/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:44:06 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/04 14:31:55 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void): RawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int x): RawBits(x << nb_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float x): RawBits(roundf(x * (1 << nb_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &rhs)
		this->RawBits = rhs.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& o, Fixed const& src)
{
	o << src.toFloat();
	return (o);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member fonction called" << std::endl;
	return (this->RawBits);
}

void Fixed::setRawBits(int raw)
{
	std::cout << "setRawBits member fonction called" << std::endl;
	this->RawBits = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->RawBits / (1 << nb_bits));
}

int Fixed::toInt(void) const
{
	return ((int)this->RawBits / (1 << nb_bits));
}
