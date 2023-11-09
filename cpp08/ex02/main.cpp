/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:55:31 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/09 14:41:15 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << "-----[MutantStack tests]-----" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "-----[std::list tests]-----" << std::endl;
	std::list<int> mlist;

	mlist.push_back(5);
	mlist.push_back(17);

	std::cout << mlist.back() << std::endl;

	mlist.pop_back();

	std::cout << mlist.size() << std::endl;

	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);

	std::list<int>::iterator list_it = mlist.begin();
	std::list<int>::iterator list_ite = mlist.end();

	++list_it;
	--list_it;
	while (list_it != list_ite)
	{
		std::cout << *list_it << std::endl;
		++list_it;
	}
	std::list<int> list_s(mlist);
	return (0);
}