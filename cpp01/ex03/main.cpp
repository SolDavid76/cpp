/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:48:53 by djanusz           #+#    #+#             */
/*   Updated: 2023/09/25 14:57:01 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

// int main(void)
// {
// 	Weapon weapon1;
// 	Weapon weapon2;

// 	weapon1.set_type("Vandal");
// 	weapon2.set_type("Phantom");
// 	HumanA human1("bob", weapon1);
// 	HumanB human2;

// 	human1.set_name("bob");
// 	human2.set_name("boby");
// 	human2.set_weapon(weapon2);

// 	human1.attack();
// 	human2.attack();
// }


int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.set_Type("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.set_Weapon(club);
		jim.attack();
		club.set_Type("some other type of club");
		jim.attack();
	}
	return 0;
}
