/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:29:31 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/19 15:54:07 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <ctime>

class PmergeMe
{
	public:
		PmergeMe(int arg_count, char **av);
		PmergeMe(const PmergeMe&src);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe&);
	private:
		PmergeMe();
		float sortDeque();
		float sortVector();
		void printValue(std::string message);
		std::deque<unsigned int> _deque;
		std::vector<unsigned int> _vector;
};

#endif