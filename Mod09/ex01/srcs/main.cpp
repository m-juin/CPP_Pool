/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:57:48 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/16 14:13:40 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main( int ac, char **av ) 
{
	if (ac < 2)
	{
		std::cout << "Need calculation as argument 1" << std::endl;
		return 1;
	}
	RPN data;
	if (data.calculate(std::string(av[1])) == true)
	{
		std::cout << "RPN : \"" << av[1] << "\" = " << data.getTop() << std::endl;
		return 0;
	}
	return 1;
}