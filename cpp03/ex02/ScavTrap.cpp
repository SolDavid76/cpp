/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:09:31 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/09 11:44:42 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "[ScavTrap]: Default constructor called" << std::endl;
	this->_name = "ScavTrap";
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap()
{
	std::cout << "[ScavTrap]: Parameter constructor called" << std::endl;
	this->_name = name;
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& src)
{
	std::cout << "[ScavTrap]: Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[ScavTrap]: Destructor called" << std::endl;
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
	if (this->_health > 0 && this->_energy > 0)
		std::cout << "[ScavTrap]: " << this->_name << " attacks " << target << " causing " << this->_damage << " point of damage!" << std::endl;
	else
		std::cout << "[ScavTrap]: " << this->_name << " has no longer enough health or energy to attack!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_health > 0)
	{
		this->_health -= amount;
		std::cout << "[ScavTrap]: " << this->_name << " has taken " << amount << " point of damage, he have " << this->_health << " remaning health!" << std::endl;
	}
	else
		std::cout << "[ScavTrap]: " << this->_name << " is already dead!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_health > 0 && this->_energy > 0)
	{
		this->_health += amount;
		std::cout << "[ScavTrap]: " << this->_name << " has been repaired of " << amount << " health point, he have " << this->_health << " remaning health!" << std::endl;
	}
	else
		std::cout << "[ScavTrap]: " << this->_name << " has no longer enough health or energy to be repaired!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "[ScavTrap]: " << this->_name << "switch to gate keeper mode" << std::endl;
}
