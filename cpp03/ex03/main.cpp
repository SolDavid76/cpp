/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:11:35 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/13 14:38:16 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap a;
	DiamondTrap b("bob");

	a.attack("GOLEMS");
	a.takeDamage(6);
	a.beRepaired(3);
	b.attack("RED");
	b.takeDamage(10);
	b.attack("GROMP");
	b.takeDamage(6);
	b.beRepaired(3);
	b.whoAmI();
}
