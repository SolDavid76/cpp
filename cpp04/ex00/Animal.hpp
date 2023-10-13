/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:51:30 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/13 18:30:45 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(const Animal& src);
		Animal& operator=(Animal const& src);
		virtual ~Animal(void);

		virtual void makeSound(void) const;
		std::string get_type(void) const;
	protected:
		std::string _type;
};

#endif
