/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 00:16:12 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/30 12:29:54 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooLowException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooHightException();
}

AForm::AForm(AForm const& src): _name(src._name), _signed(false), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	*this = src;
}

AForm& AForm::operator=(AForm const& src)
{
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

AForm::~AForm(void)
{
}

std::string AForm::get_name(void) const
{
	return (this->_name);
}

bool AForm::get_signed(void) const
{
	return (this->_signed);
}

int AForm::get_gradeToSign(void) const
{
	return (this->_gradeToSign);
}

int AForm::get_gradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void AForm::beSigned(Bureaucrat src)
{
	if (this->_gradeToSign < src.get_grade())
		throw GradeTooLowException();
	this->_signed = true;
}

std::ostream& operator<<(std::ostream& out, AForm const& src)
{
	out << "[Form]: name = " << src.get_name();
	out << ", signed = " << (src.get_signed() ? "true": "false");
	out << ", grade to sign = " << src.get_gradeToSign();
	out << ", grade to execute = " << src.get_gradeToExecute();
	return (out);
}
