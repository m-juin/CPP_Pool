/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:57:48 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/14 16:18:19 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isValidExtension(std::string filepath)
{
	size_t	pos;
	size_t	pos2;
	pos = filepath.find_last_of(".");
	if (pos == filepath.npos)
		return (false);
	pos2 = filepath.find_last_of(".csv");
	if (pos2 >= 4 && pos == (pos2 - 3) && (filepath.length() - 1 == pos2))
		return (true);
	return (false);
}

bool checkFileValidity(int ac, char **av)
{
	std::string filepath;
	if (ac < 2)
	{
		std::cerr << "Need a database as input" << std::endl;
		return (false);
	}
	filepath = std::string(av[1]);
	if (isValidExtension(filepath) == false)
	{
		std::cerr << "invalid file extension \".csv\" expected" << std::endl;
		return (false);
	}
	std::ifstream file(filepath.c_str());
	if (file.is_open() == false)
	{
		std::cerr << "The " << filepath << " file doesn't look like it exists or could not have been opened." << std::endl;
		return (false);
	}
	file.close();
	return (true);
}

int main( int ac, char **av ) 
{
	if (checkFileValidity(ac, av) == false)
		return 1;
	std::string alpha(av[1]);
	BitcoinExchange btc(alpha);
	BitcoinExchange::st_time newt;
	newt.year = 2021;
	newt.month = 5;
	newt.day = 21;
	std::cout << "2147483647 bitcoin at the date " << newt.year << "-" << newt.month << "-" << newt.day << " are valuated at " << btc.getValue(newt, 2147483647) << std::endl;
}