/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:29:32 by mjuin             #+#    #+#             */
/*   Updated: 2023/03/02 13:49:52 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::complain(std::string level)
{
	int	index;
	functionPtr functionArray[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levelArray[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (index = 0; index < 4; index++)
	{
		if (levelArray[index] == level)
			break;
	}
	if (index == 4)
		std::cerr << "Level not Found" << std::endl;
	else
		(this->*functionArray[index])();
	
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
