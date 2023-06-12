/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:57:48 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/08 16:00:15 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <algorithm>
#include "Span.hpp"

void trySpanBase()
{
	std::cout << "#     trySpanBase     #\n" << std::endl;
	Span test(5);
	try
	{
		test.addNumber(5);
		test.addNumber(10);
		test.addNumber(20);
		test.addNumber(50);
		test.addNumber(100);
		test.displaySpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void trySpanTooMuch()
{
	std::cout << "\n#     trySpanTooMuch     #\n" << std::endl;
	Span test(5);
	try
	{
		test.addNumber(5);
		test.addNumber(10);
		test.addNumber(20);
		test.addNumber(50);
		test.addNumber(100);
		test.addNumber(200);
		test.displaySpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << '\n';
	}
	
}

void tryShortBase()
{
	std::cout << "#     tryShortBase     #\n" << std::endl;
	Span test(5);
	try
	{
		test.addNumber(5);
		test.addNumber(10);
		test.addNumber(20);
		test.addNumber(50);
		test.addNumber(100);
		test.displaySpan();
		std::cout << "\nshortest Span = " << test.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << '\n';
	}
}

void tryShortTooSmall()
{
	std::cout << "#     tryShortTooSmall     #\n" << std::endl;
	Span test(2);
	try
	{
		test.addNumber(-2147483648);
		test.displaySpan();
		std::cout << "\nshortest Span = " << test.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << '\n';
	}
}

void tryShortOverflow()
{
	std::cout << "#     tryShortOverFlow     #\n" << std::endl;
	Span test(2);
	try
	{
		test.addNumber(-2147483648);
		test.addNumber(2147483647);
		test.displaySpan();
		std::cout << "\nshortest Span = " << test.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << '\n';
	}
}

void tryLongBase()
{
	std::cout << "#     tryLongBase     #\n" << std::endl;
	Span test(5);
	try
	{
		test.addNumber(5);
		test.addNumber(10);
		test.addNumber(20);
		test.addNumber(50);
		test.addNumber(100);
		test.displaySpan();
		std::cout << "\nLongest Span = " << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << '\n';
	}
}

void tryLongTooSmall()
{
	std::cout << "#     tryLongTooSmall     #\n" << std::endl;
	Span test(2);
	try
	{
		test.addNumber(-2147483648);
		test.displaySpan();
		std::cout << "\nLongest Span = " << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << '\n';
	}
}

void tryLongOverflow()
{
	std::cout << "#     tryLongOverFlow     #\n" << std::endl;
	Span test(2);
	try
	{
		test.addNumber(-2147483648);
		test.addNumber(2147483647);
		test.displaySpan();
		std::cout << "\nLongest Span = " << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << '\n';
	}
}

void tryaddRange()
{
	std::cout << "#     tryaddRange     #\n" << std::endl;
	Span test(100);
	try
	{
		test.addNumber(20);
		test.addNumber(50);
		test.displaySpan();
		test.addRange(50);
		test.displaySpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << '\n';
	}
}


int main( void ) 
{
	trySpanBase();
	trySpanTooMuch();
	tryShortBase();
	tryShortTooSmall();
	tryShortOverflow();
	tryLongBase();
	tryLongTooSmall();
	tryLongOverflow();
	srand(time(NULL));
	tryaddRange();
}
