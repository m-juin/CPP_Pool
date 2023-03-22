/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:20:17 by mjuin             #+#    #+#             */
/*   Updated: 2023/03/02 14:31:43 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>

int main(int ac, char **av)
{
	if (ac < 2 || ac > 2)
	{
		std::cerr << "Wrong Amount of argument !" << std::endl;
		return (1);
	}
	Harl newHarl;
	newHarl.complain(av[1]);
}