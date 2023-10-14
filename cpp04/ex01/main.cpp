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
	std::cout << "-----[Animal array example]-----" << std::endl;
	Animal* animals[4];
	for (int i = 0; i < 4; i++)
	{
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();
	for (int i = 0; i < 4; i++)
		delete animals[i];
	std::cout << "-----[Brain deep copy test]-----" << std::endl;
	Cat riri;
	Dog fifi;

	riri.get_brain()->set_ideas("Meow... *Wana eat*", 0);
	riri.get_brain()->set_ideas("Meow... *Wana sleep*", 1);
	riri.get_brain()->set_ideas("Meow... *Wana eat*", 2);
	riri.get_brain()->set_ideas("Meow... *Wana sleep*", 3);
	riri.get_brain()->set_ideas("Meow... *Wana eat*", 4);
	riri.get_brain()->set_ideas("Meow... *Wana play*", 5);
	riri.print_ideas();

	Cat riri_copy(riri);
	riri_copy.get_brain()->set_ideas("Meow... *Wana sleep*", 5);
	riri.print_ideas();
	riri_copy.print_ideas();

	return (0);
}

// const Animal* meta = new Animal();
// const Animal* i = new Dog();
// const Animal* j = new Cat();

// std::cout << "Type of meta " << meta->get_type() << std::endl;
// std::cout << "Type of i = " << i->get_type() << std::endl;
// std::cout << "Type of j = " << j->get_type() << std::endl;
// meta->makeSound();
// i->makeSound();
// j->makeSound();

// delete meta;
// delete i;
// delete j;
