/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:29:31 by mjuin             #+#    #+#             */
/*   Updated: 2023/07/27 12:21:58 by mjuin            ###   ########.fr       */
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
	private:
		class Pair
		{
			private:
				Pair(const Pair&src);
				Pair &operator=(const Pair&);
				long int _min;
				long int _max;
				unsigned int _index;
			public:
				~Pair();
				Pair(int min, int max, size_t index);
				long int getMax();
				long int getMin();
				unsigned int getIndex();
				void setIndex();
		};
		PmergeMe();
		float sortDeque();
		float sortVector();
		void sortPairMax(std::deque<Pair> pairdeque);
		void printValue(std::string message);
		std::deque<unsigned int> _deque;
		std::vector<unsigned int> _vector;
};

#endif