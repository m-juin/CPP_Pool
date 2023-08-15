/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:57:48 by mjuin             #+#    #+#             */
/*   Updated: 2023/08/15 11:01:29 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main( int ac, char **av ) 
{
	if (ac != 2)
	{
		std::cout << "Need calculation as first on only argument." << std::endl;
		return 1;
	}
	RPN data;
	std::string base(av[1]);
	std::string output;
	if (data.calculate(base) == true)
	{
		base.erase(std::remove(base.begin(), base.end(), ' '), base.end());
  		for (std::string::iterator it = base.begin(); it != base.end(); ++it)
		{
        	output += *it;
        	if (it + 1 != base.end()) {
            	output += ' ';
        	}
    	}
		std::cout << "RPN : \"" << output << "\" = " << data.getTop() << std::endl;
		return 0;
	}
	return 1;
}