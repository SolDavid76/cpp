/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 00:16:26 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/31 12:35:22 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
    Bureaucrat bob("bob", 1);
	Intern  randomIntern;
	AForm* form;

    form = randomIntern.makeForm("presidential pardon", "Bob");
    std::cout << bob << std::endl;
    std::cout << *form << std::endl;
    bob.signForm(*form);
    bob.executeForm(*form);
	form = randomIntern.makeForm("presidential pardon", "Bob");
	delete form;

	return (0);
}
