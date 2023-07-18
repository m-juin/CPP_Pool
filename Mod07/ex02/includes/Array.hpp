/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:48:11 by mjuin             #+#    #+#             */
/*   Updated: 2023/07/03 16:07:59 by mjuin            ###   ########.fr       */
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
		const T &operator[](size_t index) const;
		unsigned int size( void );
		class InvalidIndexException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#include "../srcs/Array.tpp"

#endif
