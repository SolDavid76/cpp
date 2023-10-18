/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:13:56 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/17 12:06:10 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "[Dog]: Default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain;
}

Dog::Dog(const Dog& src)
{
	std::cout << "[Dog]: Copy constructor called" << std::endl;
	this->_brain = new Brain;
	*this = src;
}

Dog& Dog::operator=(Dog const& src)
{
	std::cout << "[Dog]: Copy assignement Dog operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "[Dog]: Destructor called" << std::endl;
	delete this->_brain;
}

void Dog::makeSound(void) const
{
	std::cout << "[Dog]: bark" << std::endl;
}

Brain* Dog::get_brain(void) const
{
	return (this->_brain);
}

void Dog::print_ideas(void) const
{
	std::cout << "-----[start of ideas]-----" << std::endl;
	for (int i = 0; (i < 100 && !this->_brain->get_ideas()[i].empty()); i++)
		std::cout << "Idea[" << i << "]: " << this->_brain->get_ideas()[i] << std::endl;
	std::cout << "-----[end of ideas]-----" << std::endl;
}
