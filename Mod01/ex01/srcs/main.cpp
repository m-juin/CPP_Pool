/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:20:17 by mjuin             #+#    #+#             */
/*   Updated: 2023/03/29 11:38:55 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie* zombieHorde( int N, std::string name );

int main()
{
	int		Amount = 8;
	Zombie 	*Horde = zombieHorde(Amount, "Bobs");
	for (int i = 0; i < Amount; i++)
	{
		Horde[i].announce();
	}
	if (Amount < 0)
		return (0); 
	delete[] Horde;
}