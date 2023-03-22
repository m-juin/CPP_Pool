/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:36:24 by mjuin             #+#    #+#             */
/*   Updated: 2023/02/28 16:06:08 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <Weapon.hpp>
#include <iostream>

class HumanA
{
	public:
		HumanA(std::string name, Weapon& newWeapon);
		~HumanA();
		void attack();
	private:
		std::string name;
		Weapon& weapon;
};

#endif