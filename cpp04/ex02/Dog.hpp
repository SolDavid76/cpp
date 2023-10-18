/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:10:51 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/17 12:06:31 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	public:
		Dog(void);
		Dog(const Dog& src);
		Dog& operator=(Dog const& src);
		~Dog(void);

		void makeSound(void) const;
		Brain* get_brain(void) const;
		void print_ideas(void) const;
	private:
		Brain* _brain;
};

#endif