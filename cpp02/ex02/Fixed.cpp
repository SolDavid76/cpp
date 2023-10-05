/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:44:06 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/05 11:50:47 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): RawBits(0)
{
}

Fixed::Fixed(const int x): RawBits(x << nb_bits)
{
}

Fixed::Fixed(const float x): RawBits(roundf(x * (1 << nb_bits)))
{
}

Fixed::Fixed(const Fixed& src)
{
	*this = src;
}

Fixed::~Fixed(void)
{
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
	if (this != &rhs)
		this->RawBits = rhs.getRawBits();
	return (*this);
}

/* ARITHMECTIC OPERATORS */
Fixed Fixed::operator+(Fixed const& rhs)
{
	Fixed res = this->toFloat() + rhs.toFloat();
	return (res);
}

Fixed Fixed::operator-(Fixed const& rhs)
{
	Fixed res = this->toFloat() - rhs.toFloat();
	return (res);
}

Fixed Fixed::operator*(Fixed const& rhs)
{
	Fixed res = this->toFloat() * rhs.toFloat();
	return (res);
}

Fixed Fixed::operator/(Fixed const& rhs)
{
	Fixed res = this->toFloat() / rhs.toFloat();
	return (res);
}

/* INCREMENT/DECREMENT OPERATORS */
Fixed& Fixed::operator++(void)
{
	this->RawBits++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed oldValue = *this;
	this->RawBits++;
	return (oldValue);
}

Fixed& Fixed::operator--(void)
{
	this->RawBits--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed oldValue = *this;
	this->RawBits--;
	return (oldValue);
}

/* COMPARISON OPERATORS */
bool Fixed::operator<(Fixed const& rhs)
{
	return (this->RawBits < rhs.RawBits);
}

bool Fixed::operator>(Fixed const& rhs)
{
	return (this->RawBits > rhs.RawBits);
}

bool Fixed::operator<=(Fixed const& rhs)
{
	return (this->RawBits <= rhs.RawBits);
}

bool Fixed::operator>=(Fixed const& rhs)
{
	return (this->RawBits >= rhs.RawBits);
}

bool Fixed::operator==(Fixed const& rhs)
{
	return (this->RawBits == rhs.RawBits);
}

bool Fixed::operator!=(Fixed const& rhs)
{
	return (this->RawBits != rhs.RawBits);
}

std::ostream& operator<<(std::ostream& o, Fixed const& src)
{
	o << src.toFloat();
	return (o);
}

int Fixed::getRawBits(void) const
{
	return (this->RawBits);
}

void Fixed::setRawBits(int raw)
{
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

Fixed& Fixed::min(Fixed& x, Fixed& y)
{
	return (x.RawBits < y.RawBits ? x : y);
}

Fixed const& Fixed::min(Fixed const& x, Fixed const& y)
{
	return (x.RawBits < y.RawBits ? x : y);
}

Fixed& Fixed::max(Fixed& x, Fixed&y)
{
	return (x.RawBits > y.RawBits ? x : y);
}

Fixed const& Fixed::max(Fixed const& x, Fixed const& y)
{
	return (x.RawBits > y.RawBits ? x : y);
}
