/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:48:52 by mjuin             #+#    #+#             */
/*   Updated: 2023/07/03 16:05:11 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array( void )
{
	_array = new T[0];
	_size = 0;
}

template <typename T>
Array<T>::Array( unsigned int n)
{
	_array = new T[n];
	_size = n;
	if (n != 0)
		_array[0] = n;
	for (size_t i = 1; i < n; i++)
	{
		this->_array[i] = 0;
	}
	
}

template <typename T>
Array<T>::Array( const Array&src )
{
	this->_array = new T[0];
	this->_size = 0;
	*this = src;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T>&src)
{
	if (this == &src)
		return (*this);
	delete[] this->_array;
	this->_array = new T[src._size];
	this->_size = src._size;
	for (size_t i = 0; i < this->_size; i++)
	{
		this->_array[i] = src._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array( void )
{
	delete[] this->_array;
}

template <typename T>
T &Array<T>::operator[](size_t index)
{
	if (index >= _size)
		throw Array::InvalidIndexException();
	return (this->_array[index]);
}

template <typename T>
const T &Array<T>::operator[](size_t index) const
{
	if (index >= _size)
		throw Array::InvalidIndexException();
	return (this->_array[index]);
}

template <typename T>
unsigned int Array<T>::size( void )
{
	return (_size);
}

template <typename T>
inline const char *Array<T>::InvalidIndexException::what() const throw()
{
	return ("Invalid index");
}

#endif