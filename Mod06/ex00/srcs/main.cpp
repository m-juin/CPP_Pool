/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:36:24 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/02 11:04:31 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main( int ac, char **av )
{
	if (ac < 2)
	{
		std::cerr << "No input" << std::endl;
		return 0;
	}
	ScalarConverter::convert(av[1]);

}