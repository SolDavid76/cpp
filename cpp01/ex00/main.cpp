/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:05:49 by djanusz           #+#    #+#             */
/*   Updated: 2023/09/28 16:17:53 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	bar;
	Zombie	*foo = newZombie("foo");

	bar.set_name("bar");
	bar.announce();
	foo->announce();
	randomChump("bob");
	delete (foo);
}