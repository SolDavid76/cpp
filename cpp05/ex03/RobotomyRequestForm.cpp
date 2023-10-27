/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 00:15:36 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/27 00:31:12 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src): AForm(src), _target(src._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& src)
{
	if (this != & src)
		this->_target = src._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (this->get_signed() == false)
		throw NotSignedException();
	if (executor.get_grade() > this->get_gradeToExecute())
		throw GradeTooLowException();
	static int i = 0;
	if (i % 2)
		std::cout << this->_target << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomy failed!" << std::endl;
	i++;
}
