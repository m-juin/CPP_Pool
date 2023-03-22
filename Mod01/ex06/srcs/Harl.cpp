/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:29:32 by mjuin             #+#    #+#             */
/*   Updated: 2023/03/22 12:42:50 by mjuin            ###   ########.fr       */
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

	switch (index + 1)
	{
		case 1:
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*functionArray[0])();
			std::cout << std::endl;
			__attribute__ ((fallthrough));
		case 2:
			std::cout << "[ INFO ]" << std::endl;
			(this->*functionArray[1])();
			std::cout << std::endl;
			__attribute__ ((fallthrough));
		case 3:
			std::cout << "[ WARNING ]" << std::endl;
			(this->*functionArray[2])();
			std::cout << std::endl;
			__attribute__ ((fallthrough));
		case 4:
			std::cout << "[ ERROR ]" << std::endl;
			(this->*functionArray[3])();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn\'t put enough bacon in my burger!\nIf you did, I wouldn\'t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI\'ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable!\nI want to speak to the manager now." << std::endl;
}
