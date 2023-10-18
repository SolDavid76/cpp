/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:18:09 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/18 16:47:49 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& src);
		MateriaSource& operator=(MateriaSource const& src);
		~MateriaSource(void);

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const& type);
	private:
		AMateria* _inventory[4];
};

#endif
