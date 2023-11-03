/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:31:36 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/31 11:48:13 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <string>
# include <iostream>

template<typename T>
void swap(T& x, T& y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

template<typename T>
T min(T const& x, T const& y)
{
	return (x < y ? x : y);
}

template<typename T>
T max(T const& x, T const& y)
{
	return (x > y ? x : y);
}

#endif
