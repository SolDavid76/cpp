/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 00:16:55 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/27 00:16:56 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooLowException();
	if (gradeToSign > 250 || gradeToExecute > 250)
		throw GradeTooHightException();
}

Form::Form(Form const& src)
{
	*this = src;
}

Form& Form::operator=(Form const& src)
{
	if (this != &src)
	{
		this->_signed = src._signed;
		this->_gradeToSign = src._gradeToSign;
		this->_gradeToExecute = src._gradeToExecute;
	}
	return (*this);
}

Form::~Form(void)
{
}

std::string Form::get_name(void) const
{
	return (this->_name);
}

bool Form::get_signed(void) const
{
	return (this->_signed);
}

int Form::get_gradeToSign(void) const
{
	return (this->_gradeToSign);
}

int Form::get_gradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat src)
{
	if (this->_gradeToSign < src.get_grade())
		throw GradeTooLowException();
	this->_signed = true;
}

std::ostream& operator<<(std::ostream& out, Form const& src)
{
	out << "[Form]: name = " << src.get_name();
	out << ", signed = " << (src.get_signed() ? "true": "false");
	out << ", grade to sign = " << src.get_gradeToSign();
	out << ", grade to execute = " << src.get_gradeToExecute();
	return (out);
}
