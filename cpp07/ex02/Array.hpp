/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:12:37 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/03 15:53:57 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <iostream>

template<typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const& src);
		Array& operator=(Array const& src);
		~Array(void);

		T& operator[](unsigned int index);

		unsigned int size(void);
	private:
		T* _Array;
		unsigned int _size;
};

template<typename T>
Array<T>::Array(void)
{
	this->_Array = NULL;
	this->_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	this->_Array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		this->_Array[i] = 0;
	this->_size = n;
}

template<typename T>
Array<T>::Array(Array const& src)
{
	this->_Array = new T[0];
	*this = src;
}

template<typename T>
Array<T>& Array<T>::operator=(Array const& src)
{
	if (this != &src)
	{
		delete[] this->_Array;
		this->_Array = new T[src._size];
		for (unsigned int i = 0; i < src._size; i++)
			this->_Array[i] = src._Array[i];
		this->_size = src._size;
	}
	return (*this);
}

template<typename T>
Array<T>::~Array(void)
{
	delete[] this->_Array;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index > this->size() - 1)
		throw std::exception();
	else
		return (this->_Array[index]);
}

template<typename T>
unsigned int Array<T>::size(void)
{
	return (this->_size);
}

#endif
