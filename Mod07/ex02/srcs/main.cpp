/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:57:48 by mjuin             #+#    #+#             */
/*   Updated: 2023/07/05 10:26:47 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int display(int i )
{
	std::cout << i << " ";
	return (i);
}

int add(int i)
{
	return (i + 1);
}


void baseTry()
{
	std::cout << "\n#	BasicTry	#\n\n";
	Array<int> test(5);
	try
	{
		for (size_t i = 0; i < test.size(); i++)
		{
			std::cout << "Array[" << i << "] = " << test[i] << std::endl;
		}
		std::cout << "\n#	Modifying Value	#\n\n";
		test[1] = 1;
		test[3] = 3;
		for (size_t i = 0; i < test.size(); i++)
		{
			std::cout << "Array[" << i << "] = " << test[i] << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void baseTryEmpty()
{
	std::cout << "\n#	EmptyTry	#\n\n";
	Array<int> test;
	try
	{
		for (size_t i = 0; i < 1; i++)
		{
			std::cout << "Array[" << i << "] = " << test[i] << std::endl;
		}
		std::cout << "\n#	Modifying Value	#\n\n";
		for (size_t i = 0; i < 1; i++)
		{
			std::cout << "Array[" << i << "] = " << test[i] << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void invalidIndexTry()
{
	std::cout << "\n#	InvalidIndexTry	#\n\n";
	Array<int> test(5);
	try
	{
		for (size_t i = 0; i < test.size() + 1; i++)
		{
			std::cout << "Array[" << i << "] = " << test[i] << std::endl;
		}
		std::cout << "\n#	Modifying Value	#\n\n";
		for (size_t i = 0; i < test.size() + 1; i++)
		{
			std::cout << "Array[" << i << "] = " << test[i] << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void TryCopyConstructor()
{
	std::cout << "\n#	CopyConstructorTry	#\n\n";
	Array<int> *test = new Array<int>(5);
	Array<int> *test2 = new Array<int>(*test);
	try
	{
		for (size_t i = 0; i < test->size(); i++)
		{
			std::cout << "Array1[" << i << "] = " << (*test)[i] << std::endl;
		}
		for (size_t i = 0; i < test->size(); i++)
		{
			std::cout << "Array2[" << i << "] = " << (*test2)[i] << std::endl;
		}
		std::cout << "\n#	Modifying Value	#\n\n";
		(*test)[0] = 1;
		for (size_t i = 0; i < test->size(); i++)
		{
			std::cout << "Array1[" << i << "] = " << (*test)[i] << std::endl;
		}
		delete (test);
		for (size_t i = 0; i < test2->size(); i++)
		{
			std::cout << "Array2[" << i << "] = " << (*test2)[i] << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete (test2);
}

void TryAssignement()
{
	std::cout << "\n#	AssignementTry	#\n\n";
	Array<int> *test = new Array<int>(5);
	Array<int> *test2 = new Array<int>();
	(*test2) = (*test);
	try
	{
		for (size_t i = 0; i < test->size(); i++)
		{
			std::cout << "Array1[" << i << "] = " << (*test)[i] << std::endl;
		}
		for (size_t i = 0; i < test->size(); i++)
		{
			std::cout << "Array2[" << i << "] = " << (*test2)[i] << std::endl;
		}
		std::cout << "\n#	Modifying Value	#\n\n";
		(*test)[0] = 1;
		for (size_t i = 0; i < test->size(); i++)
		{
			std::cout << "Array1[" << i << "] = " << (*test)[i] << std::endl;
		}
		delete (test);
		for (size_t i = 0; i < test2->size(); i++)
		{
			std::cout << "Array2[" << i << "] = " << (*test2)[i] << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete (test2);
}

int main( void ) 
{
	baseTry();
	baseTryEmpty();
	invalidIndexTry();
	TryCopyConstructor();
	TryAssignement();
}
