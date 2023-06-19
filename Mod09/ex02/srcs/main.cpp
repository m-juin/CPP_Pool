/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:57:48 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/19 11:45:26 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

int main( int ac, char **av ) 
{
	if (ac < 2)
	{
		std::cerr << "Need some number to sort !" << std::endl;
		return (1);
	}
	else if (ac < 3 )
	{
		std::cerr << "Need more than one argument to sort !" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe merger(ac - 1, av);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}