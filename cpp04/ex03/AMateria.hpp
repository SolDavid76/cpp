/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:22:51 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/18 16:54:49 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>

class ICharacter;

class AMateria
{
	public:
		AMateria(void);
		AMateria(std::string const& type);
		AMateria(const AMateria& src);
		AMateria& operator=(AMateria const& src);
		virtual ~AMateria(void);

		std::string const& get_type(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target) = 0;
	protected:
		std::string _type;
};

#endif
