/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:57:48 by mjuin             #+#    #+#             */
/*   Updated: 2023/07/05 10:20:14 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void display(T &i)
{
	std::cout << i << " ";
}


void testInt()
{
	int array[5] = {0, 1, 2, 3, 4};

	std::cout << "array = ";
	::iter(array, 5, display<int>);
	std::cout << std::endl;
}

void testFloat()
{
	float array[5] = {0.0f, 1.1f, 2.2f, 3.3f, 4.4f};

	std::cout << "array = ";
	iter(array, 5, display<float>);
	std::cout << std::endl;
}

void testString()
{
	std::string array[3] = {"Hello", "Hella", "Helle"};
	std::cout << "array = ";
	iter(array, 3, display<std::string>);
	std::cout << std::endl;
}
int main( void ) 
{
	std::cout << "#   int   #\n" << std::endl;
	testInt();
	std::cout << "\n#   Float   #\n" << std::endl;
	testFloat();
	std::cout << "\n#   String   #\n" << std::endl;
	testString();
}