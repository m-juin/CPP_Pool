/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:57:48 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/05 11:41:53 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int display(int i )
{
	std::cout << i << " ";
	return (i);
}

int add(int i)
{
	return (i + 1);
}

int main( void ) 
{
	int array[5] = {0, 1, 2, 3, 4};

	std::cout << "array = ";
	::iter(array, 5, &display);
	std::cout << std::endl;
	::iter(array, 3, &add);
	std::cout << "array = ";
	::iter(array, 5, &display);
	std::cout << std::endl;
}