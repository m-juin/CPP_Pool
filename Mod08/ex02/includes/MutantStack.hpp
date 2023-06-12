/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:22:45 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/12 15:04:21 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template<class T> 
class MutantStack : public std::stack<T>
{
	private:
	public:
		MutantStack() { };
		MutantStack(const MutantStack &src)
		{
			*this = src;
		}
		MutantStack operator=(const MutantStack &src)
		{
			if (this == &src)
				return *this;
			return (*this);
		}
		~MutantStack() { };

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin()
		{
			return (std::stack<T>::c.begin());
		}
		iterator end()
		{
			return (std::stack<T>::c.end());
		}
};

#endif
