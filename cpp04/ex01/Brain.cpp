/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:59:57 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/13 19:29:25 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "[Brain]: Default constructor called" << std::endl;
}

Brain::Brain(const Brain& src)
{
	std::cout << "[Brain]: Copy constructor called" << std::endl;
	*this = src;
}

Brain& Brain::operator=(Brain const& src)
{
	std::cout << "[Brain]: Copy assignement Brain operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "[Brain]: Destructor called" << std::endl;
}

const std::string* Brain::get_ideas(void) const
{
	return (this->_ideas);
}

void Brain::set_ideas(std::string idea, unsigned int index)
{
	this->_ideas[index] = idea;
}
