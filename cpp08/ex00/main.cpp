/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:59:31 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/08 11:29:14 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
    std::vector<int> v;
	v.push_back(1);
	v.push_back(23);
	v.push_back(42);
	v.push_back(99);
	v.push_back(-3);

	std::vector<int>::const_iterator it = easyfind(v, 23);
	std::cout << *it << std::endl;
	std::cout << *(++it) << std::endl;
}
