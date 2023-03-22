/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:01:57 by mjuin             #+#    #+#             */
/*   Updated: 2023/01/10 11:20:49 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char const **av)
{
	int 		posx;
	int			posy;
	std::string str;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		posx = 1;
		while (posx < ac)
		{
			posy = 0;
			while (av[posx][posy])
			{
				str += std::toupper(av[posx][posy]);
				posy++;
			}
			posx++;
		}
		std::cout << str << std::endl;
	}
	return 0;
}
