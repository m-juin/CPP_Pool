/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:36:15 by mjuin             #+#    #+#             */
/*   Updated: 2023/03/29 11:37:47 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);
	Zombie *Horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		Horde[i].setName(name);
	return (Horde);
}