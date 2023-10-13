/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:20:19 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/13 14:45:08 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	this->_name = "FragTrap";
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout << "[FragTrap]: " << this->_name << " Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_name = name;
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout << "[FragTrap]: " << this->_name << " Parameter constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src)
{
	std::cout << "[FragTrap]: Copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "[FragTrap]: " << this->_name << " Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const& src)
{
	std::cout << "[FragTrap]: Copy assignment operator called" << std::endl;

	if (this != &src)
	{
		this->_name = src._name;
		this->_health = src._health;
		this->_energy = src._energy;
		this->_damage = src._damage;
	}
	return (*this);
}

void FragTrap::attack(const std::string& target)
{
	this->_energy--;
	if (this->_health > 0 && this->_energy > 0)
		std::cout << "[FragTrap]: " << this->_name << " attacks " << target << " causing " << this->_damage << " point of damage!" << std::endl;
	else
		std::cout << "[FragTrap]: " << this->_name << " has no longer enough health or energy to attack!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "[FragTrap]: " << this->_name << " wait for a a hight five !" << std::endl;
}
