/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:41:16 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/31 12:28:28 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
}

Intern::Intern(Intern const& src)
{
	*this = src;
}

Intern& Intern::operator=(Intern const& src)
{
	(void)src;
	return (*this);
}

Intern::~Intern(void)
{
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm* res = NULL;
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
			res = forms[i];
		else
			delete forms[i];
	}
	if (res == NULL)
		std::cout << "Intern cannot find " << name << " form" << std::endl;
	else
		std::cout << "Intern creates " << name << std::endl;
	return (res);
}
