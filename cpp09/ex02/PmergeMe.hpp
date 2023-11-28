/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:52:34 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/27 12:33:27 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <iostream>
# include <sstream>
# include <algorithm>
# include <cmath>
# include <deque>
# include <ctime>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(PmergeMe const& rhs);
		PmergeMe& operator=(PmergeMe const& rhs);
		~PmergeMe();


		int parseInput(int ac, char **av);
		void sortVector(int begin, int end);
		void sortVector(std::vector<int>& vec);
		void sortVector(void);


		void save_solo();
		std::vector<std::pair<int, int> > make_all_pair_vector();
		void sortEachPair(std::deque<std::pair<int, int> >& pairDeque);
		void sortEachPair(std::vector<std::pair<int, int> >& pairVector);
		void sortPairVector(std::vector<std::pair<int , int> >& pairVector);
		void insertionSortPairs(std::vector<std::pair<int , int> >& pairVector, int lenght);
		void insertionSortPairs(std::deque<std::pair<int , int> >& pairDeque, int length);

		void insertElement( std::deque< std::pair<int, int> > & pairDeque, std::pair<int, int> element, int length);
		void insertElement( std::vector< std::pair<int, int> > & pairVector, std::pair<int, int> element, int lenght);

		void time();

		void makeSortedDeque( std::deque< std::pair<int, int> > & pairDeque);
		void makeSortedVector( std::vector< std::pair<int, int> > & pairVector);

		int next_jacob();
		int powjacob(int n);
		void insertFirstDeque(int toInsert, int toFind);
		void insertFirstVector(int toInsert, int toFind);

		int findIndex(int x);
		void insertAtIndex(int element);

		std::deque<std::pair<int, int> > make_all_pair_deque();
		void sortPairDeque(std::deque<std::pair<int , int> >& pairDeque);
		void sortDeque(void);
	private:
		std::vector<int> _unsortedVector;
		std::vector<int> _sortedVector;
		std::deque<int> _unsortedDeque;
		std::deque<int> _sortedDeque;

		int	_soloNb;
};

# endif
