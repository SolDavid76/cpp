/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:05:49 by djanusz           #+#    #+#             */
/*   Updated: 2023/09/22 13:36:39 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	bar("bar");
	Zombie	*foo = newZombie("foo");

	bar.announce();
	foo->announce();
	randomChump("bob");
	delete (foo);
}