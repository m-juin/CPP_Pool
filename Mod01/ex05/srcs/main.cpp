/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:20:17 by mjuin             #+#    #+#             */
/*   Updated: 2023/03/02 12:56:11 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>

int main(void)
{
	Harl newHarl;

	std::cout << "#DEBUG" << std::endl;
	newHarl.complain("DEBUG");
	std::cout << "#INFO" << std::endl;
	newHarl.complain("INFO");
	std::cout << "#WARNING" << std::endl;
	newHarl.complain("WARNING");
	std::cout << "#ERROR" << std::endl;
	newHarl.complain("ERROR");
	std::cout << "#ERR2OR" << std::endl;
	newHarl.complain("ERR2OR");
}