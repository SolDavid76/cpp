/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:52:36 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/28 14:42:03 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _soloNb(-1)
{
}

PmergeMe& PmergeMe::operator=(PmergeMe const& rhs)
{
	if (this != &rhs)
	{
		this->_unsortedVector = rhs._unsortedVector;
		this->_sortedVector = rhs._sortedVector;
		this->_unsortedDeque = rhs._unsortedDeque;
		this->_sortedDeque = rhs._sortedDeque;
		this->_soloNb = rhs._soloNb;
	}
	return (*this);
}

PmergeMe::PmergeMe(PmergeMe const& rhs)
{
	*this = rhs;
}

PmergeMe::~PmergeMe()
{
}

int PmergeMe::parseInput(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::string input = av[i];

		bool flag = true;
		for (size_t j = 0; j < input.size(); j++)
			if (!std::isdigit(input[j]))
				flag = false;
		if (flag)
		{
			int num = atoi(input.c_str());
			if (num < 0 || num > 2147483647)
				return (1);
			this->_unsortedVector.push_back(num);
			this->_unsortedDeque.push_back(num);
		}
		else
			return (1);
	}
	return (0);
}

void PmergeMe::save_solo()
{
	_soloNb = _unsortedVector.back();
	_unsortedVector.pop_back();
}

std::vector<std::pair<int, int> > PmergeMe::make_all_pair_vector()
{
	std::vector<std::pair<int, int> > pairVector;
	int first = -1;

	for (std::vector<int>::iterator it = _unsortedVector.begin(); it != _unsortedVector.end(); ++it)
	{
		if (first == -1)
			first = *it;
		else
		{
			pairVector.push_back(std::make_pair(first, *it));
			first = -1;
		}
	}
	return (pairVector);
}

void PmergeMe::sortEachPair(std::vector<std::pair<int, int> >& pairVector)
{
	for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); ++it)
	{
		if (it->first > it->second)
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
}

void PmergeMe::sortEachPair(std::deque<std::pair<int, int> >& pairDeque)
{
	for (std::deque<std::pair<int, int> >::iterator it = pairDeque.begin(); it != pairDeque.end(); ++it)
	{
		if (it->first > it->second)
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
}

void PmergeMe::insertElement( std::vector< std::pair<int, int> > & pairVector, std::pair<int, int> element, int length)
{
	if (length < 0)
		pairVector[0] = element;
	else if (element.second >= pairVector[length].second)
		pairVector[length + 1] = element;
	else
	{
			pairVector[length + 1] = pairVector[length];
			insertElement(pairVector, element, length - 1);
	}
}

void PmergeMe::insertElement( std::deque< std::pair<int, int> > & pairDeque, std::pair<int, int> element, int length)
{
	if (length < 0)
		pairDeque[0] = element;
	else if (element.second >= pairDeque[length].second)
		pairDeque[length + 1] = element;
	else
	{
			pairDeque[length + 1] = pairDeque[length];
			insertElement(pairDeque, element, length - 1);
	}
}

void PmergeMe::insertionSortPairs(std::vector<std::pair<int , int> >& pairVector, int length)
{
	if (length < 1)
		return ;
	else
	{
		insertionSortPairs(pairVector, length - 1);
		insertElement(pairVector, pairVector[length], length - 1);
	}
}

void PmergeMe::insertionSortPairs(std::deque<std::pair<int , int> >& pairDeque, int length)
{
	if (length < 1)
		return ;
	else
	{
		insertionSortPairs(pairDeque, length - 1);
		insertElement(pairDeque, pairDeque[length], length - 1);
	}
}

void PmergeMe::sortPairVector(std::vector<std::pair<int , int> >& pairVector)
{
	int length = pairVector.size();
	insertionSortPairs(pairVector, length - 1);

}

void PmergeMe::sortPairDeque(std::deque<std::pair<int , int> >& pairDeque)
{
	int length = pairDeque.size();
	insertionSortPairs(pairDeque, length - 1);

}

void PmergeMe::makeSortedVector(std::vector< std::pair<int, int> > & pairVector)
{
	for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); ++it)
		_sortedVector.push_back(it->second);
	int curr_jacob = 0;
	int prev_jacob = 0;
	while (_sortedVector.size() < (_unsortedVector.size() / 2) * 2)
	{
		int tmp = next_jacob();
		if (tmp > static_cast<int>(pairVector.size()))
			tmp = pairVector.size();
		curr_jacob = tmp;
		while (curr_jacob-- > prev_jacob)
			insertFirstVector(pairVector[curr_jacob].first, curr_jacob + (_sortedVector.size() - (_unsortedVector.size() / 2)));
		prev_jacob = tmp;
	}

	if (_soloNb >= 0) 
	{
		if (_sortedVector.empty() || _soloNb > *(_sortedVector.end() - 1))
			_sortedVector.push_back(_soloNb);
		else
			insertFirstVector(_soloNb, _sortedVector.size());
	}
}

void PmergeMe::makeSortedDeque(std::deque< std::pair<int, int> > & pairDeque)
{
	for (std::deque<std::pair<int, int> >::iterator it = pairDeque.begin(); it != pairDeque.end(); ++it)
		_sortedDeque.push_back(it->second);
	int curr_jacob = 0;
	int prev_jacob = 0;
	while (_sortedDeque.size() < (_unsortedDeque.size() / 2) * 2)
	{
		int tmp = next_jacob();
		if (tmp > static_cast<int>(pairDeque.size()))
			tmp = pairDeque.size();
		curr_jacob = tmp;
		while (curr_jacob-- > prev_jacob)
			insertFirstDeque(pairDeque[curr_jacob].first, curr_jacob + (_sortedDeque.size() - (_unsortedDeque.size() / 2)));
		prev_jacob = tmp;
	}

	if (_soloNb >= 0) 
	{
		if (_sortedDeque.empty() || _soloNb > *(_sortedDeque.end() - 1))
			_sortedDeque.push_back(_soloNb);
		else
			insertFirstDeque(_soloNb, _sortedDeque.size());
	}
}

int PmergeMe::powjacob(int n) {
	static int res = 0;
	if (res < n) {
		int i = 0;
		while (res <= n) {
			res = pow(2, i++) - 1;
		}
	}
	return (res);
}

int	PmergeMe::next_jacob()
{
	static std::vector<int> a(2, 1);
	a.push_back(*(a.end() - 1) + 2 * *(a.end() - 2));

	return (*(a.end() - 2));
}

void PmergeMe::insertAtIndex(int element)
{
	int index = findIndex(element);
	_sortedVector.insert(_sortedVector.begin() + index, element);
}

int PmergeMe::findIndex(int x)
{
	int min = 0;
	int max = _sortedVector.size();

	while (min < max)
	{
		int mid = (min + max) / 2;
		if (x < _sortedVector[mid])
			max = mid;
		else
			min = mid + 1;
	}
	return (min);
}

void	PmergeMe::insertFirstVector(int toInsert, int toFind)
{
	int indexMax = toFind;
	int indexMin = -1;

	if (indexMax > static_cast<int>(_sortedVector.size()))
		indexMax = static_cast<int>(_sortedVector.size());

	while(indexMax - indexMin > 1) 
	{
		int mid = (indexMax + indexMin) / 2;
		if (_sortedVector[mid] > toInsert)
			indexMax = mid;
		else
			indexMin = mid;
	}
	_sortedVector.insert(_sortedVector.begin() + indexMax, toInsert);
}

void	PmergeMe::insertFirstDeque(int toInsert, int toFind)
{
	int indexMax = toFind;
	int indexMin = -1;

	if (indexMax > static_cast<int>(_sortedDeque.size()))
		indexMax = static_cast<int>(_sortedDeque.size());

	while(indexMax - indexMin > 1) 
	{
		int mid = (indexMax + indexMin) / 2;
		if (_sortedDeque[mid] > toInsert)
			indexMax = mid;
		else
			indexMin = mid;
	}
	_sortedDeque.insert(_sortedDeque.begin() + indexMax, toInsert);
}


void PmergeMe::sortVector(void)
{
	bool has_soloNb = _unsortedVector.size() % 2 != 0;
	if (has_soloNb)
		save_solo();
	std::vector<std::pair<int, int> > pairVector = make_all_pair_vector();
	sortEachPair(pairVector);
	sortPairVector(pairVector);
	makeSortedVector(pairVector);
}


std::deque<std::pair<int, int> > PmergeMe::make_all_pair_deque()
{
	std::deque<std::pair<int, int> > pairDeque;
	int first = -1;

	for (std::deque<int>::iterator it = _unsortedDeque.begin(); it != _unsortedDeque.end(); ++it)
	{
		if (first == -1)
			first = *it;
		else
		{
			pairDeque.push_back(std::make_pair(first, *it));
			first = -1;
		}
	}
	return (pairDeque);
}

void PmergeMe::sortDeque(void)
{
	bool has_soloNb = _unsortedDeque.size() % 2 != 0;
	if (has_soloNb)
		save_solo();
	std::deque<std::pair<int, int> > pairDeque = make_all_pair_deque();
	sortEachPair(pairDeque);
	sortPairDeque(pairDeque);
	makeSortedDeque(pairDeque);
}


void PmergeMe::time()
{
	std::cout << "Before:	";
	for (std::vector<int>::iterator it = _unsortedVector.begin(); it != _unsortedVector.end(); ++it)
			std::cout << *it << " ";
	std::cout << std::endl;
	std::clock_t start = clock();
	sortVector();
	std::clock_t end = clock();

	std::clock_t start2 = clock();
	sortDeque();
	std::clock_t end2 = clock();

	std::cout << "After:	";
	for (std::vector<int>::iterator it = _sortedVector.begin(); it != _sortedVector.end(); ++it)
			std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of "<< _sortedVector.size() << " elements with std::vector : "<< static_cast<double>((end - start) / (CLOCKS_PER_SEC / 1000000)) << " us" << std::endl;
	std::cout << "Time to process a range of "<< _sortedDeque.size() << " elements with std::deque : "<< static_cast<double>((end2 - start2) / (CLOCKS_PER_SEC / 1000000)) << " us" << std::endl;
	// std::cout << (std::is_sorted(_sortedVector.begin(), _sortedVector.end()) ? "Sorted" : "Not sorted") << std::endl;
}
