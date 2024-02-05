/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:20:17 by mjuin             #+#    #+#             */
/*   Updated: 2023/04/03 14:33:10 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>

int main(int ac, char **av)
{
	if (ac < 2 || ac > 2)
	{
		std::cout << "Wrong Amount of argument !" << std::endl;
		return (1);
	}
	Harl newHarl;
	newHarl.complain(av[1]);
}