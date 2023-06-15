#include <BitcoinExchange.hpp>
#include <string>
#include <cstdlib>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string path)
{
	std::ifstream file;
	file.open(path.c_str());
	std::string line;
	int count = 0;
	while (std::getline(file, line))
	{
		if (count++ == 0)
			continue;
		st_time date;
		int index = line.find(',');
		date = getdatevalue(line.substr(0, index));
		if (date.day == -1)
			throw BitcoinExchange::InvalidDateFormatException();
		else if (date.day == -2)
			throw BitcoinExchange::InvalidDateException();
		float value;
		try
		{
			value = std::strtof(line.substr(index + 1, line.npos).c_str(), NULL);
		}
		catch(const std::exception& e)
		{
			if (errno == ERANGE)
			{
				std::cerr << "conversion of value \"" << line.substr(index + 1, line.npos) << "\" may cause an overflow or an underflow !" << '\n';
			}
		}
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
			return (quantity * (*it).second);
		}
	}
	return quantity * (*it2).second;
}

BitcoinExchange::st_time BitcoinExchange::getdatevalue(std::string value)
{
	BitcoinExchange::st_time ltm;
	int index = value.find_first_of('-', 0);
	if (index != 4 || value[index + 3] != '-' || value[index + 6] != '\0')
	{
		ltm.day = -1;
		return (ltm);
	}
	ltm.year = std::atoi(value.substr(0, index).c_str());
	ltm.month = std::atoi(value.substr(index + 1, index + 3).c_str());
	ltm.day = std::atoi(value.substr(index + 4, index + 6).c_str());
	if (ltm.month > 12 || ((ltm.month == 1 || ltm.month == 3 || ltm.month == 5 || ltm.month == 7 || ltm.month == 8 || ltm.month == 10 || ltm.month == 12) && ltm.day > 31) ||
	((ltm.month == 2 || ltm.month == 4 || ltm.month == 6 || ltm.month == 9 || ltm.month == 11) && ltm.day > 30))
	{
		ltm.day = -2;
		return (ltm);
	}
	else if (ltm.day < 0 || ltm.month < 0 || ltm.year < 0)
	{
		ltm.day = 0;
		return (ltm);
	}
	return (ltm);
}

std::string BitcoinExchange::Exchange(std::string line)
{
	size_t sep = line.find(" | ");
	std::string ret;
	std::string str_date;
	if (sep == line.npos)
	{
		ret = ("Error: Invalid line format => " + line);
		throw std::runtime_error(ret);
	}
	str_date = line.substr(0, sep);
	st_time date = getdatevalue(str_date);
	if (date.day <= 0)
	{
		ret = ("Error: Bad input => " + str_date);
		throw std::runtime_error(ret);
	}
	float Quantity = 0;
	try
	{
		Quantity = std::atof(line.substr(sep + 3, line.npos).c_str());
		if (Quantity < 0)
		{
			ret = ("Error: not a positive number.");
			throw std::runtime_error(ret);
		}
		else if (Quantity > 1000)
		{
			ret = ("Error: too large a number.");
			throw std::runtime_error(ret);
		}
	}
	catch (const std::exception &e)
	{
		throw std::runtime_error(e.what());
	}
	std::stringstream s;
	float valuated = getValue(date, Quantity);
	s << str_date << " => " << Quantity << " = " << valuated;
	return (s.str());
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

const char *BitcoinExchange::InvalidDateFormatException::what() const throw()
{
	return ("Invalid date format !");
}

const char *BitcoinExchange::InvalidDateException::what() const throw()
{
	return ("Invalid date !");
}

std::ostream &operator<<(std::ostream &os, const BitcoinExchange::st_time &time)
{
	os << time.year << "-" << time.month << "-" << time.day;
	return os;
}

const char *BitcoinExchange::InvalidFileFormat::what() const throw()
{
	return ("Invalid line format !");
}
