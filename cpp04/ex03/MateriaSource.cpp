/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:24:31 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/18 17:10:59 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "[MateriaSource]: Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	std::cout << "[MateriaSource]: Copy constructor called" << std::endl;
	*this = src;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& src)
{
	std::cout << "[MateriaSource]: Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->_inventory[i];
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "[Character]: Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			std::cout << "[learn]: learned " << m->get_type() << std::endl;
			this->_inventory[i] = m;
			return;
		}
	}
	std::cout << "[learn]: can't learn " << m->get_type() << " not enought space in the inventory" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i]->get_type() == type)
			return (this->_inventory[i]->clone());
	}
	return (NULL);
}
