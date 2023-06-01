/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:18:01 by mjuin             #+#    #+#             */
/*   Updated: 2023/05/30 12:54:07 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void tryBase()
{
	try
	{
		Bureaucrat toto("toto", 75);
		std::cout << toto << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}

void tryMax()
{
	try
	{
		Bureaucrat toto("toto", 1);
		std::cout << toto << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}

void tryMin()
{
	try
	{
		Bureaucrat toto("toto", 150);
		std::cout << toto << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}

void tryOverMax()
{
	try
	{
		Bureaucrat toto("toto", 0);
		std::cout << toto << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}

void tryOverMin()
{
	try
	{
		Bureaucrat toto("toto", 151);
		std::cout << toto << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}

int main()
{
	tryBase();
	tryMin();
	tryMax();
	tryOverMin();
	tryOverMax();
}