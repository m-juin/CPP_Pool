/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:10:30 by mjuin             #+#    #+#             */
/*   Updated: 2023/07/14 09:27:02 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

void trymstackBase()
{

	std::cout << "#     MStack Base     #\n\n";
	MutantStack<int>	mstack;
	std::cout << "MStack Size = " << mstack.size() << " so MStack is empty ? " << std::boolalpha << mstack.empty() << std::endl;
	mstack.push(5);
	std::cout << "MStack add " << mstack.top() << std::endl;
	mstack.push(15);
	std::cout << "MStack add " << mstack.top() << std::endl;
	std::cout << "MStack Size = " << mstack.size() << " so MStack is empty ? " << std::boolalpha << mstack.empty() << std::endl;
	mstack.pop();
	std::cout << "MStack pop " << std::endl;
	std::cout << "MStack Size = " << mstack.size() << " so MStack is empty ? " << std::boolalpha << mstack.empty() << std::endl;
}

void trymstackIterator()
{
	std::cout << "\n#     MStack Iterator     #\n\n";
	MutantStack<int> mstack;
	std::cout << "MStack Size = " << mstack.size() << std::endl;
	std::cout << "MStack values : " << std::endl;
	MutantStack<int>::iterator it2 = mstack.end();
	for (MutantStack<int>::iterator it = mstack.begin(); it != it2; it++)
	{
		std::cout << *it << std::endl;
	}
	mstack.push(5);
	std::cout << "MStack add " << mstack.top() << std::endl;
	mstack.push(15);
	std::cout << "MStack add " << mstack.top() << std::endl;
	mstack.push(-2);
	std::cout << "MStack add " << mstack.top() << std::endl;
	mstack.push(50);
	std::cout << "MStack add " << mstack.top() << std::endl;
	mstack.push(25);
	std::cout << "MStack add " << mstack.top() << std::endl;
	mstack.push(17);
	std::cout << "MStack add " << mstack.top() << std::endl;
	it2 = mstack.end();
	std::cout << "MStack Size = " << mstack.size() << std::endl;
	std::cout << "MStack values : " << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it < it2; it++)
	{
		std::cout << *it << std::endl;
	}
}

void tryListIterator()
{
	std::cout << "\n#     List Iterator     #\n\n";
	std::list<int> mstack;
	std::cout << "List Size = " << mstack.size() << std::endl;
	std::cout << "List values : " << std::endl;
	std::list<int>::iterator it2 = mstack.end();
	for (std::list<int>::iterator it = mstack.begin(); it != it2; it++)
	{
		std::cout << *it << std::endl;
	}
	mstack.push_back(5);
	std::cout << "List add " << *mstack.end() << std::endl;
	mstack.push_back(15);
	std::cout << "List add " << *mstack.end() << std::endl;
	mstack.push_back(-2);
	std::cout << "List add " << *mstack.end() << std::endl;
	mstack.push_back(50);
	std::cout << "List add " << *mstack.end() << std::endl;
	mstack.push_back(25);
	std::cout << "List add " << *mstack.end() << std::endl;
	mstack.push_back(17);
	std::cout << "List add " << *mstack.end() << std::endl;
	it2 = mstack.end();
	std::cout << "List Size = " << mstack.size() << std::endl;
	std::cout << "List values : " << std::endl;
	for (std::list<int>::iterator it = mstack.begin(); it != it2; it++)
	{
		std::cout << *it << std::endl;
	}
}

void trystackBase()
{

	std::cout << "\n#     Stack Base     #\n\n";
	std::stack<int>	mstack;
	std::cout << "Stack Size = " << mstack.size() << " so Stack is empty ? " << std::boolalpha << mstack.empty() << std::endl;
	mstack.push(5);
	std::cout << "Stack add " << mstack.top() << std::endl;
	mstack.push(15);
	std::cout << "Stack add " << mstack.top() << std::endl;
	std::cout << "Stack Size = " << mstack.size() << " so Stack is empty ? " << std::boolalpha << mstack.empty() << std::endl;
	mstack.pop();
	std::cout << "Stack pop " << std::endl;
	std::cout << "Stack Size = " << mstack.size() << " so Stack is empty ? " << std::boolalpha << mstack.empty() << std::endl;
}

void trysubject()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	it = mstack.begin();
	ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return ;
}

void trymstackdeep()
{

	std::cout << "\n#     Stack copy     #\n\n";
	MutantStack<int>	mstack;
	std::cout << "Stack1 Size = " << mstack.size() << " so Stack1 is empty ? " << std::boolalpha << mstack.empty() << std::endl;
	mstack.push(5);
	std::cout << "Stack1 add " << mstack.top() << std::endl;
	mstack.push(15);
	std::cout << "Stack1 add " << mstack.top() << std::endl;
	std::cout << "Stack1 Size = " << mstack.size() << " so Stack1 is empty ? " << std::boolalpha << mstack.empty() << std::endl;
	mstack.pop();
	std::cout << "Stack1 pop " << std::endl;
	std::cout << "Stack1 Size = " << mstack.size() << " so Stack1 is empty ? " << std::boolalpha << mstack.empty() << std::endl;
	MutantStack<int>	mstack2(mstack);
	std::cout << "Stack2 Size = " << mstack2.size() << " so Stack2 is empty ? " << std::boolalpha << mstack2.empty() << std::endl;
	mstack.pop();
	std::cout << "Stack1 pop " << std::endl;
	std::cout << "Stack1 Size = " << mstack.size() << " so Stack1 is empty ? " << std::boolalpha << mstack.empty() << std::endl;
	std::cout << "Stack2 Size = " << mstack2.size() << " so Stack2 is empty ? " << std::boolalpha << mstack2.empty() << std::endl;
}

int main()
{
	trymstackBase();
	tryListIterator();
	trymstackIterator();
	trystackBase();
	trymstackdeep();
}