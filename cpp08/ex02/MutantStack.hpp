/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:55:56 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/09 14:29:04 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUTANTSTACK_HPP
# define NUTANTSTACK_HPP

# include <list>
# include <stack>
# include <iostream>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename MutantStack<T>::container_type::iterator iterator;
		MutantStack(void);
		MutantStack(MutantStack const& src);
		MutantStack& operator=(MutantStack const& src);
		~MutantStack(void);

		iterator begin(void);
		iterator end(void);
};

template <typename T>
MutantStack<T>::MutantStack(void)
{
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const& src)
{
	*this = src;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const& src)
{
	std::stack<T>::operator=(src);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (this->c.end());
}

#endif
