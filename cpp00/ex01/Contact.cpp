/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:48:03 by djanusz           #+#    #+#             */
/*   Updated: 2023/09/18 14:48:31 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact(void)
{
	// std::cout << "#DEBUG: Contact constructor called" << std::endl;
}

Contact::~Contact(void)
{
	// std::cout << "#DEBUG: Contact destructor called" << std::endl;
}

std::string	Contact::get_firstname(void)
{
	return (this->_firstname);
}

void	Contact::set_firstname(std::string str)
{
	this->_firstname = str;
}

std::string	Contact::get_lastname(void)
{
	return (this->_lastname);
}

void	Contact::set_lastname(std::string str)
{
	this->_lastname = str;
}

std::string	Contact::get_nickname(void)
{
	return (this->_nickname);
}

void	Contact::set_nickname(std::string str)
{
	this->_nickname = str;
}

std::string	Contact::get_phone(void)
{
	return (this->_phone);
}

void	Contact::set_phone(std::string str)
{
	this->_phone = str;
}

std::string	Contact::get_secret(void)
{
	return (this->_secret);
}

void	Contact::set_secret(std::string str)
{
	this->_secret = str;
}
