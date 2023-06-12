/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:57:48 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/07 12:40:43 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <algorithm>
#include "easyfind.hpp"

void TryListBase(int searched)
{
	std::list<int> list;
	for (size_t i = 0; i < 100; i++)
	{
		list.push_back(i);
	}
	std::list<int>::iterator it = list.begin();
	std :: cout << "\n#     List     #\n\n";
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << "list[" << i << "] = " << *it << std::endl;
		advance(it, 1);
	}
	easyfind(list, searched);
}

void TryListDouble(int searched)
{
	std::list<int> list;
	for (size_t i = 0; i < 100; i++)
	{
		list.push_back(i);
	}
	std::list<int>::iterator it = list.begin();
	std::replace(list.begin(), list.end(), 50, 10);
	std :: cout << "\n#     ListDouble     #\n\n";
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << "list[" << i << "] = " << *it << std::endl;
		advance(it, 1);
	}
	easyfind(list, searched);
}

void TryListInvalid(int searched)
{
	std::list<int> list;
	for (size_t i = 0; i < 100; i++)
	{
		list.push_back(i);
	}
	std::list<int>::iterator it = list.begin();
	std :: cout << "\n#     List     #\n\n";
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << "list[" << i << "] = " << *it << std::endl;
		advance(it, 1);
	}
	easyfind(list, searched);
}

void TryListEmpty(int searched)
{
	std::list<int> list;
	std :: cout << "\n#     ListEmpty     #\n\n";
	easyfind(list, searched);
}

void TryVectorBase(int searched)
{
	std::vector<int> Vector;
	for (size_t i = 0; i < 100; i++)
	{
		Vector.push_back(i);
	}
	std::vector<int>::iterator it = Vector.begin();
	std :: cout << "\n#     Vector     #\n\n";
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << "Vector[" << i << "] = " << *it << std::endl;
		advance(it, 1);
	}
	easyfind(Vector, searched);
}

void TryVectorDouble(int searched)
{
	std::vector<int> Vector;
	for (size_t i = 0; i < 100; i++)
	{
		Vector.push_back(i);
	}
	std::vector<int>::iterator it = Vector.begin();
	std::replace(Vector.begin(), Vector.end(), 50, 10);
	std :: cout << "\n#     VectorDouble     #\n\n";
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << "Vector[" << i << "] = " << *it << std::endl;
		advance(it, 1);
	}
	easyfind(Vector, searched);
}

void TryVectorInvalid(int searched)
{
	std::vector<int> Vector;
	for (size_t i = 0; i < 100; i++)
	{
		Vector.push_back(i);
	}
	std::vector<int>::iterator it = Vector.begin();
	std :: cout << "\n#     List     #\n\n";
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << "Vector[" << i << "] = " << *it << std::endl;
		advance(it, 1);
	}
	easyfind(Vector, searched);
}

void TryVectorEmpty(int searched)
{
	std::vector<int> Vector;
	std :: cout << "\n#     VectorEmpty     #\n\n";
	easyfind(Vector, searched);
}

int main( void ) 
{
	TryListBase(15);
	TryListDouble(10);
	TryListInvalid(250);
	TryListEmpty(10);
	TryVectorBase(15);
	TryVectorDouble(10);
	TryVectorInvalid(250);
	TryVectorEmpty(10);
}