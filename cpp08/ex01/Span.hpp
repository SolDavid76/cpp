/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:32:08 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/08 16:48:07 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <limits>
# include <vector>
# include <iostream>
# include <algorithm>

class Span
{
	public:
		Span(unsigned int n);
		Span(Span const& src);
		Span& operator=(Span const& src);
		~Span(void);

		void addNumber(int x);
		void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
	private:
		unsigned int _n;
		std::vector<int> _array;
};

#endif
