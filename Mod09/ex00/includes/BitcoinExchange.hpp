/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:47:12 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/14 16:19:16 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>

class BitcoinExchange
{

public:
	struct st_time
	{
		int year;
		int month;
		int day;

		bool operator<(const st_time &other) const;
		bool operator<=(const st_time &other) const;
	};
	BitcoinExchange(std::string path);
	BitcoinExchange(const BitcoinExchange &src);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &);
	float getValue(st_time date, float quantity);

private:
	BitcoinExchange();
	std::map<st_time, float> _bitcoinValues;
};

#endif