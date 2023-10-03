/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:42:03 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/03 16:41:29 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{
}

HumanB::~HumanB(void)
{
}

void HumanB::set_name(std::string name)
{
	this->_name = name;
}

void HumanB::set_Weapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack(void)
{
	if (this->_weapon == NULL)
		std::cout << this->_name << " cannot attack i don't have weapon" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->get_Type() << std::endl;
}
