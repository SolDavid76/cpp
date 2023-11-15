/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:35:48 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/15 12:40:41 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <string>
# include <iostream>
# include <cstddef>

template<typename T>
void iter(T* array, size_t len, void(*f)(T))
{
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

#endif
