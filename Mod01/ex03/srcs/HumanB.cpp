/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:41:58 by mjuin             #+#    #+#             */
/*   Updated: 2023/02/28 16:24:08 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <HumanB.hpp>

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	if (this->weapon != NULL)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks with his hands" << std::endl;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
	this->weapon = &newWeapon;
}
