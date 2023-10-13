/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:50:34 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/13 18:57:37 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	std::cout << "-----[Animal tests]-----" << std::endl;
	const Animal* meta = new Animal();
	const Animal* i = new Dog();
	const Animal* j = new Cat();

	std::cout << "Type of meta " << meta->get_type() << std::endl;
	std::cout << "Type of i = " << i->get_type() << std::endl;
	std::cout << "Type of j = " << j->get_type() << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();

	delete meta;
	delete i;
	delete j;

	return (0);
}
