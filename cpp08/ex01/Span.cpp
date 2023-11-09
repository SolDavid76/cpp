/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:39:19 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/08 16:50:31 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n)
{
	this->_n = n;
}

Span::Span(Span const& src)
{
	*this = src;
}

Span& Span::operator=(Span const& src)
{
	if (this != &src)
	{
		this->_n = src._n;
		this->_array = src._array;
	}
	return (*this);
}

Span::~Span(void)
{
}

void Span::addNumber(int x)
{
	if (this->_array.size() >= this->_n)
		throw std::exception();
	this->_array.push_back(x);
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator it = start; it != end; it++)
		this->addNumber(*it);
}

unsigned int Span::shortestSpan(void)
{
	if (this->_array.size() < 2)
		throw std::exception();
	unsigned int res = std::numeric_limits<unsigned int>::max();
	for (std::vector<int>::iterator it0 = this->_array.begin(); it0 != this->_array.end(); it0++)
	{
		for (std::vector<int>::iterator it1 = it0 + 1; it1 != this->_array.end(); it1++)
		{
			if ((unsigned int)(abs(*it0 - *it1)) < res)
				res = abs(*it0 - *it1);
		}
	}
	return (res);
}

unsigned int Span::longestSpan(void)
{
	if (this->_array.size() < 2)
		throw std::exception();
	return (*(std::max_element(this->_array.begin(), this->_array.end())) - *(std::min_element(this->_array.begin(), this->_array.end())));
}
