/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:02:30 by djanusz           #+#    #+#             */
/*   Updated: 2023/09/25 14:55:39 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon): _name(name), _weapon(weapon)
{
}

HumanA::~HumanA(void)
{
}

void HumanA::set_name(std::string name)
{
	this->_name = name;
}

void HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.get_Type() << std::endl;
}
