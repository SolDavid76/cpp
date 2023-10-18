/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:32:17 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/18 17:39:32 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	std::cout << "[Character]: Default constructor called" << std::endl;
	this->_name = "#DEFAULT#";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name)
{
	std::cout << "[Character]: Parameter constructor called" << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& src)
{
	std::cout << "[Character]: Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	*this = src;
}

Character& Character::operator=(Character const& src)
{
	std::cout << "[Character]: Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
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

Character::~Character(void)
{
	std::cout << "[Character]: Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
}

std::string const& Character::get_name(void) const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			std::cout << "[equip]: equiping " << m->get_type() << " at the " << i << " slot" << std::endl;
			this->_inventory[i] = m;
			return;
		}
	}
	std::cout << "[equip]: can't equip " << m->get_type() << " not enought space in the inventory" << std::endl;
}

void Character::unequip(int idx)
{
	if (0 <= idx && idx <= 3)
	{
		if (this->_inventory[idx])
			std::cout << "[unequip]: droping " << this->_inventory[idx]->get_type() << " at the " << idx << " slot" << std::endl;
		else
			std::cout << "[unequip]: nothing to drop at the " << idx << " slot" << std::endl;
		this->_inventory[idx] = NULL;
	}
	else
		std::cout << "[unequip]: invalid index!" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (0 <= idx && idx <= 3)
	{
		if (this->_inventory[idx])
			this->_inventory[idx]->use(target);
		else
			std::cout << "[use]: nothing to use at the " << idx << " slot" << std::endl;
	}
	else
		std::cout << "[use]: invalid index!" << std::endl;
}
