/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:49:12 by djanusz           #+#    #+#             */
/*   Updated: 2023/09/18 14:49:43 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(void)
{
	// std::cout << "#DEBUG: PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "#DEBUG: PhoneBook destructor called" << std::endl;
}

Contact	*PhoneBook::get_contactlist(void)
{
	return (this->_contactlist);
}
