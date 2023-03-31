/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:16:50 by mjuin             #+#    #+#             */
/*   Updated: 2023/03/29 11:41:01 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string &getType();
		void setType(std::string newType);
	private:
		std::string type;
};

#endif