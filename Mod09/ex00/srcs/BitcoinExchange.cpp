#include <BitcoinExchange.hpp>
#include <string>
#include <cstdlib>

BitcoinExchange::st_time getdatevalue(std::string value)
{
	BitcoinExchange::st_time ltm;
	int index = value.find_first_of('-', 0);
	ltm.year = std::atoi(value.substr(0, index).c_str());
	ltm.month = std::atoi(value.substr(index + 1, index + 3).c_str());
	ltm.day = std::atoi(value.substr(index + 4, index + 6).c_str());
	return (ltm);
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string path)
{
	std::ifstream file(path.c_str());
	std::string line;
	int count = 0;
	while (std::getline(file, line))
	{
		if (count++ == 0)
			continue;
		int index = line.find(',');
		st_time date = getdatevalue(line.substr(0, index));
		float value = std::atof(line.substr(index + 1, line.npos).c_str());
		this->_bitcoinValues.insert(std::make_pair<st_time, float>(date, value));
	}
}

float	BitcoinExchange::getValue(st_time date, float quantity)
{
	std::map<st_time, float>::iterator it2 = this->_bitcoinValues.end();
	for (std::map<st_time, float>::iterator it = this->_bitcoinValues.begin(); it != it2; it++)
	{
		if (((*it).first <= date) == false)
		{
			if (it != this->_bitcoinValues.begin())
				it--;
			//std::cout << "Year = " << (*it).first.year << " Month = " << (*it).first.month << " Day = " << (*it).first.day << " value is  " << (*it).second << std::endl;
			return (quantity * (*it).second);
		}
	}
	return quantity * (*it2).second;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this == &src)
		return (*this);
	this->_bitcoinValues = src._bitcoinValues;
	return (*this);
}

bool BitcoinExchange::st_time::operator<(const st_time &other) const
{
	{
		if (year != other.year)
			return (year < other.year);
		if (month != other.month)
			return (month < other.month);
		return (day < other.day);
	}
}

bool BitcoinExchange::st_time::operator<=(const st_time &other) const
{
	{
		if (year != other.year)
			return (year <= other.year);
		if (month != other.month)
			return (month <= other.month);
		return (day <= other.day);
	}
}
