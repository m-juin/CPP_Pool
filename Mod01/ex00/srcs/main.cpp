/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:20:17 by mjuin             #+#    #+#             */
/*   Updated: 2023/02/28 11:33:28 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

int main()
{
	Zombie *Bob = newZombie("Bob");

	randomChump("Toto");
	Bob->announce();
	delete(Bob);
}