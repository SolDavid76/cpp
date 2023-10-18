/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:44:16 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/17 12:02:56 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "[Cat]: Default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain;
}

Cat::Cat(const Cat& src)
{
	std::cout << "[Cat]: Copy constructor called" << std::endl;
	this->_brain = new Brain;
	*this = src;
}

Cat& Cat::operator=(Cat const& src)
{
	std::cout << "[Cat]: Copy assignement Cat operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "[Cat]: Destructor called" << std::endl;
	delete this->_brain;
}

void Cat::makeSound(void) const
{
	std::cout << "[Cat]: meowww" << std::endl;
}

Brain* Cat::get_brain(void) const
{
	return (this->_brain);
}

void Cat::print_ideas(void) const
{
	std::cout << "-----[start of ideas]-----" << std::endl;
	for (int i = 0; (i < 100 && !this->_brain->get_ideas()[i].empty()); i++)
		std::cout << "Idea[" << i << "]: " << this->_brain->get_ideas()[i] << std::endl;
	std::cout << "-----[end of ideas]-----" << std::endl;
}

