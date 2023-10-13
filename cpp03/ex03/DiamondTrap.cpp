/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:33:40 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/13 14:44:30 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap()
{
	ClapTrap::_name = "DiamondTrap_clap_name";
	this->_name = "DiamondTrap";
	this->_health = FragTrap::_health;
	this->_energy = ScavTrap::_energy;
	this->_damage = FragTrap::_damage;
	std::cout << "[DiamondTrap]: " << this->_name << " Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_health = FragTrap::_health;
	this->_energy = ScavTrap::_energy;
	this->_damage = FragTrap::_damage;
	std::cout << "[DiamondTrap]: " << this->_name << " Parameter constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
{
	std::cout << "[DiamondTrap]: Copy constructor called" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "[DiamondTrap]: " << this->_name << " Destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& src)
{
	std::cout << "[DiamondTrap]: Copy assignment operator called" << std::endl;

	if (this != &src)
	{
		this->_name = src._name;
		this->_health = src._health;
		this->_energy = src._energy;
		this->_damage = src._damage;
	}
	return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
	this->_energy--;
	if (this->_health > 0 && this->_energy > 0)
		std::cout << "[DiamondTrap]: " << this->_name << " attacks " << target << " causing " << this->_damage << " point of damage!" << std::endl;
	else
		std::cout << "[DiamondTrap]: " << this->_name << " has no longer enough health or energy to attack!" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "[DiamondTrap]: " << this->_name << std::endl;
	std::cout << "[ClapTrap from DiamondTrap]: " << ClapTrap::_name << std::endl;
}
