/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:36:24 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/29 10:25:38 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int	choosed = (std::rand() % 3);
	switch (choosed)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			break;
	}
	return (NULL);
}

void identify(Base* p)
{
	std::string	type;
	if (dynamic_cast<A*>(p) != NULL)
		type = 'A';
	else if (dynamic_cast<B*>(p) != NULL)
		type = 'B';
	else if (dynamic_cast<C*>(p) != NULL)
		type = 'C';
	else
		type = "NULL";
	std::cout << "Class type (Identified by pointer) = " << type << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "Class type (Identified by reference) = " << 'A' << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "Class type (Identified by reference) = " << 'B' << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "Class type (Identified by reference) = " << 'C' << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}

int main( void )
{
	std::srand((unsigned) time(0));
	Base *generated = generate();
	identify(generated);
	identify(*generated);
	identify(NULL);
	delete(generated);
}