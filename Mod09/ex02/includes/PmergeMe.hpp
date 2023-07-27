/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:29:31 by mjuin             #+#    #+#             */
/*   Updated: 2023/07/27 18:09:39 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cerrno>

class PmergeMe
{
	public:
		PmergeMe(int arg_count, char **av);
		PmergeMe(const PmergeMe&src);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe&);
		class Pair
		{
			private:
				Pair();
				long int _min;
				long int _max;
				unsigned int _index;
			public:
				~Pair();
				Pair(const Pair &src);
				Pair &operator=(const Pair &src);
				Pair(int min, int max, size_t index);
				long int getMax();
				long int getMin();
				unsigned int getIndex();
				void setIndex(size_t index);
		};
	private:
		PmergeMe();
		long sortDeque();
		long sortVector();
		void sortPairMax(std::deque<Pair> *pairdeque, size_t size);
		void sortPairMax(std::vector<Pair> *pairdeque, size_t size);
		void printValue(std::string message, int Container, bool all);
		void insertSort(std::deque<Pair> pairdeque);
		void insertSort(std::vector<Pair> pairvector);
		void BinaryInsertDeque(unsigned int element, unsigned int min, unsigned int max);
		void BinaryInsertVector(unsigned int element, unsigned int min, unsigned int max);
		void Verify();
		std::deque<unsigned int> _deque;
		std::vector<unsigned int> _vector;
};

#endif