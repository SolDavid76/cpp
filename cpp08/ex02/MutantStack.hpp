/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:55:56 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/15 16:45:56 by djanusz          ###   ########.fr       */
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
		typedef typename MutantStack<T>::container_type::const_iterator const_iterator;
		typedef typename MutantStack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename MutantStack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		MutantStack(void);
		MutantStack(MutantStack const& src);
		MutantStack& operator=(MutantStack const& src);
		~MutantStack(void);

		iterator begin(void);
		iterator end(void);
		const_iterator cbegin(void);
		const_iterator cend(void);
		reverse_iterator rbegin(void);
		reverse_iterator rend(void);
		const_reverse_iterator crbegin(void);
		const_reverse_iterator crend(void);
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

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin(void)
{
	return (this->c.cbegin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend(void)
{
	return (this->c.cend());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void)
{
	return (this->c.regin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void)
{
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin(void)
{
	return (this->c.crbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend(void)
{
	return (this->c.crend());
}

#endif
