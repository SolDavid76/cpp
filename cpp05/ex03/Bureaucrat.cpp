/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 00:16:19 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/27 00:22:59 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
    	throw GradeTooLowException();
	if (grade > 250)
		throw GradeTooHightException();
}

Bureaucrat::Bureaucrat(Bureaucrat const& src)
{
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& src)
{
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
}

std::string Bureaucrat::get_name(void) const
{
	return (this->_name);
}

int Bureaucrat::get_grade(void) const
{
	return (this->_grade);
}

void Bureaucrat::promote(void)
{
	if (this->_grade == 1)
		throw GradeTooHightException();
	this->_grade--;
}

void Bureaucrat::demote(void)
{
	if (this->_grade == 250)
		throw GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.get_name() << std::endl;
	}
	catch (std::exception const& e)
	{
		std::cout << this->_name << " couldn't sign " << form.get_name() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.get_name() << std::endl;
	}
	catch (std::exception const& e)
	{
		std::cout << this->_name << " couldn't execute " << form.get_name() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const& src)
{
	out << "[Bureaucrat]: name = " << src.get_name();
	out << ", grade = " << src.get_grade();
	return (out);
}
