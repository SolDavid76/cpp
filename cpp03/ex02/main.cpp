/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:11:35 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/10 15:27:51 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	ClapTrap a;
	FragTrap b("bob");

	a.attack("GOLEMS");
	a.takeDamage(6);
	a.beRepaired(3);
	b.attack("RED");
	b.takeDamage(10);
	b.attack("GROMP");
	b.takeDamage(6);
	b.beRepaired(3);
	b.highFivesGuys();
}
