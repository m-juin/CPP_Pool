/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:47:12 by mjuin             #+#    #+#             */
/*   Updated: 2023/07/18 09:32:56 by mjuin            ###   ########.fr       */
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
	BitcoinExchange();
	BitcoinExchange(std::string path);
	BitcoinExchange(const BitcoinExchange &src);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &);
	float getValue(st_time date, float quantity);
	BitcoinExchange::st_time getdatevalue(std::string value);
	std::string	Exchange(std::string line);
	class InvalidDateFormatException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class InvalidDateException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class InvalidFileFormat : public std::exception
	{
		public:
			const char *what() const throw();
	};
		
private:
	std::map<st_time, float> _bitcoinValues;
};

	std::ostream	&operator<<(std::ostream& os, const BitcoinExchange::st_time& time);

#endif