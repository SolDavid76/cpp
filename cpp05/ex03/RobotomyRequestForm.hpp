/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 00:15:51 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/27 00:15:52 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTMYREQUESTFORM_HPP
# define ROBOTMYREQUESTFORM_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const& src);
		RobotomyRequestForm& operator=(RobotomyRequestForm const& src);
		~RobotomyRequestForm(void);

		void execute(Bureaucrat const& executor) const;
	private:
		std::string _target;
};

#endif
