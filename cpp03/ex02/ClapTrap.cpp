/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:12:46 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/11 12:40:10 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("ClapTrap"), _health(10), _energy(10), _damage(0)
{
	std::cout << "[ClapTrap]: " << this->_name << " Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _health(10), _energy(10), _damage(0)
{
	std::cout << "[ClapTrap]: " << this->_name << " Parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "[ClapTrap]: Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "[ClapTrap]: " << this->_name << " Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& src)
{
	std::cout << "[ClapTrap]: Copy assignment operator called" << std::endl;

	if (this != &src)
	{
		this->_name = src._name;
		this->_health = src._health;
		this->_energy = src._energy;
		this->_damage = src._damage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	this->_energy--;
	if (this->_health > 0 && this->_energy > 0)
		std::cout << "[ClapTrap]: " << this->_name << " attacks " << target << " causing " << this->_damage << " point of damage!" << std::endl;
	else
		std::cout << "[ClapTrap]: " << this->_name << " has no longer enough health or energy to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_health > 0)
	{
		this->_health -= amount;
		std::cout << "[ClapTrap]: " << this->_name << " has taken " << amount << " point of damage, he have " << this->_health << " remaning health!" << std::endl;
	}
	else
		std::cout << "[ClapTrap]: " << this->_name << " is already dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_energy--;
	if (this->_health > 0 && this->_energy > 0)
	{
		this->_health += amount;
		std::cout << "[ClapTrap]: " << this->_name << " has been repaired of " << amount << " health point, he have " << this->_health << " remaning health!" << std::endl;
	}
	else
		std::cout << "[ClapTrap]: " << this->_name << " has no longer enough health or energy to be repaired!" << std::endl;
}
