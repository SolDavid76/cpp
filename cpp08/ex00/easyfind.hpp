/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:03:50 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/08 11:25:32 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>

template<typename T>
typename T::const_iterator easyfind(T const& src, int x)
{
	typename T::const_iterator res = std::find(src.begin(), src.end(), x);
	if (res == src.end())
		throw std::exception();
	return (res);
}

#endif
