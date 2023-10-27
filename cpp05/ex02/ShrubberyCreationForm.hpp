/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 00:15:53 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/27 00:15:54 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATION_HPP
# define SHRUBBERYCREATION_HPP

# include <string>
# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const& src);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const& src);
		~ShrubberyCreationForm(void);

		void execute(Bureaucrat const& executor) const;
	private:
		std::string _target;
};

#endif
