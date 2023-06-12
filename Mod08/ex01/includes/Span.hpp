/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:50:58 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/08 14:26:15 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
class Span
{
	public:
		Span(unsigned int size);
		Span(const Span&src);
		~Span();
		Span &operator=(const Span&);
		void addNumber(int number);
		int	shortestSpan();
		int longestSpan();
		void displaySpan();
		void addRange(size_t amount);
		class TooMuchNumberException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class OverflowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class TooFewNumberException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	private:
		Span();
		std::vector<int> _list;
		unsigned int _max;
};

#endif