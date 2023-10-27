/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:36:07 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/27 15:41:03 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const& src);
		Intern& operator=(Intern const& src);
		~Intern(void);

		AForm* makeForm(std::string name, std::string target);
};

#endif
