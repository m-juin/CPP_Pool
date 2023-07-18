/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:57:48 by mjuin             #+#    #+#             */
/*   Updated: 2023/07/06 11:30:21 by mjuin            ###   ########.fr       */
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
	it = easyfind(list, searched);
	if (it != list.end())
		std::cout << searched << " found" << std::endl;
	else
		std::cout << searched << " not found" << std::endl;
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
	it = easyfind(list, searched);
	if (it == list.end())
		std::cout << searched << " not found" << std::endl;
	else
		std::cout << searched << " found" << std::endl;
}

void TryListInvalid(int searched)
{
	std::list<int> list;
	for (size_t i = 0; i < 100; i++)
	{
		list.push_back(i);
	}
	std::list<int>::iterator it = list.begin();
	std :: cout << "\n#     List Invalid     #\n\n";
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << "list[" << i << "] = " << *it << std::endl;
		advance(it, 1);
	}
	it = easyfind(list, searched);
	if (it == list.end())
		std::cout << searched << " not found" << std::endl;
	else
		std::cout << searched << " found" << std::endl;
}

void TryListEmpty(int searched)
{
	std::list<int> list;
	std :: cout << "\n#     ListEmpty     #\n\n";
	std::list<int>::iterator it = easyfind(list, searched);
	if (it != list.end())
		std::cout << searched << " found" << std::endl;
	else
		std::cout << searched << " not found" << std::endl;
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
	it = easyfind(Vector, searched);
	if (it != Vector.end())
		std::cout << searched << " found" << std::endl;
	else
		std::cout << searched << " not found" << std::endl;
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
	it = easyfind(Vector, searched);
	if (it != Vector.end())
		std::cout << searched << " found" << std::endl;
	else
		std::cout << searched << " not found" << std::endl;
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
	it = easyfind(Vector, searched);
	if (it != Vector.end())
		std::cout << searched << " found" << std::endl;
	else
		std::cout << searched << " not found" << std::endl;
}

void TryVectorEmpty(int searched)
{
	std::vector<int> Vector;
	std :: cout << "\n#     VectorEmpty     #\n\n";
	std::vector<int>::iterator it = easyfind(Vector, searched);
	if (it != Vector.end())
		std::cout << searched << " found" << std::endl;
	else
		std::cout << searched << " not found" << std::endl;
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