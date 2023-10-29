/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:58:17 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/29 14:17:05 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data* ptr = new Data;
	ptr->name = "Bob";
	ptr->age = 19;

	uintptr_t raw = serialize(ptr);
	Data* new_ptr = deserialize(raw);
	std::cout << "Name = " << new_ptr->name << ", age = " << new_ptr->age << std::endl;
}