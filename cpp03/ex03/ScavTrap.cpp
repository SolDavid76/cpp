/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:09:31 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/13 14:45:25 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	this->_name = "ScavTrap";
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout << "[ScavTrap]: " << this->_name << " Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_name = name;
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout << "[ScavTrap]: " << this->_name << " Parameter constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src)
{
	std::cout << "[ScavTrap]: Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[ScavTrap]: " << this->_name << " Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& src)
{
	std::cout << "[ScavTrap]: Copy assignment operator called" << std::endl;

	if (this != &src)
	{
		this->_name = src._name;
		this->_health = src._health;
		this->_energy = src._energy;
		this->_damage = src._damage;
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	this->_energy--;
	if (this->_health > 0 && this->_energy > 0)
		std::cout << "[ScavTrap]: " << this->_name << " attacks " << target << " causing " << this->_damage << " point of damage!" << std::endl;
	else
		std::cout << "[ScavTrap]: " << this->_name << " has no longer enough health or energy to attack!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "[ScavTrap]: " << this->_name << " switch to gate keeper mode" << std::endl;
}
