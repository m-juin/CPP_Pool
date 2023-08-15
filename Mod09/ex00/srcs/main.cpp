/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:57:48 by mjuin             #+#    #+#             */
/*   Updated: 2023/08/15 10:13:22 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool checkFileValidity(int ac, char **av)
{
	std::string filepath;
	if (ac < 2)
	{
		std::cerr << "Need a database as input" << std::endl;
		return (false);
	}
	filepath = std::string(av[1]);
	std::ifstream file(filepath.c_str());
	if (file.is_open() == false)
	{
		std::cerr << "The " << filepath << " file doesn't look like it exists or could not have been opened." << std::endl;
		return (false);
	}
	file.close();
	return (true);
}

void readFile(std::string filepath, BitcoinExchange btc)
{
	std::ifstream file(filepath.c_str());
	std::string line;
	int count = 0;
	while (std::getline(file, line))
	{
		if (count++ == 0)
		{
			if (line != "date | value")
			{
				std::cerr << "Error: Bad file format => " << line << std::endl;
				return ;
			}
			continue;
		}
		try
		{
			std::string value = btc.Exchange(line);
			std::cout << value << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
}

int main( int ac, char **av ) 
{
	if (checkFileValidity(ac, av) == false)
		return 1;
	BitcoinExchange btc;
	try
	{
		btc = (BitcoinExchange("data.csv"));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	readFile(av[1], btc);
}
