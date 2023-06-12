/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:48:11 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/05 15:15:13 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
	private:
		unsigned int _size;
		T *_array;
	public:
		Array<T>( void );
		Array<T>( unsigned int n );
		Array<T>( const Array&src );
		Array &operator=(const Array&);
		~Array<T>();
		T &operator[](size_t index);
		unsigned int size( void );
		class InvalidIndexException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#include "../srcs/Array.tpp"

#endif
