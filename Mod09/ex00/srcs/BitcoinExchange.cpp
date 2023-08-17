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
		{
			if (line != "date,exchange_rate")
			{
				std::string ret = ("Error: Invalid first data line format => " + line);
				throw std::runtime_error(ret);
			}
			continue;
		}
		st_time date;
		long unsigned int index = line.find(',');
		if (index == line.npos)
		{
			std::string ret = ("Error: No , present in data line => " + line);
			throw std::runtime_error(ret);
		}
		long unsigned int pos = index + 1;
		int dot = 0;
		while (line[pos] != '\0')
		{
			if (line[pos] == '.' && dot != 0)
			{
				std::string ret = ("Error: Double . in data line => " + line);
				throw std::runtime_error(ret);
			}
			else if (line[pos] == '.')
				dot++;
			else if (std::isdigit(line[pos]) == false)
			{
				std::string ret = ("Error: non digit char in data line => " + line);
				throw std::runtime_error(ret);
			}
			pos++;
		}
		if (pos == index + 1)
		{
			std::string ret = ("Error: no value in data line => " + line);
			throw std::runtime_error(ret);
		}
		date = getDateValue(line.substr(0, index));
		if (date.day == -1)
			throw BitcoinExchange::InvalidDateFormatException();
		else if (date.day == -2 || date.day == 0)
			throw BitcoinExchange::InvalidDateException();
		double value;
		try
		{
			value = std::strtof(line.substr(index + 1, line.npos).c_str(), NULL);
		}
		catch (const std::exception &e)
		{
			if (errno == ERANGE)
			{
				std::cerr << "conversion of value \"" << line.substr(index + 1, line.npos) << "\" of data may cause an overflow or an underflow !" << '\n';
			}
		}
		_bitcoinValues[date] = value;
	}
	if (this->_bitcoinValues.size() == 0)
		throw std::runtime_error("Error ! Empty Database !");
}

double BitcoinExchange::getValue(st_time date, double quantity)
{
	std::map<st_time, double>::iterator it2 = this->_bitcoinValues.end();
	for (std::map<st_time, double>::iterator it = this->_bitcoinValues.begin(); it != it2; it++)
	{
		if (((*it).first <= date) == false)
		{
			if (it != this->_bitcoinValues.begin())
				it--;
			else if (((*it).first < date) == false)
				throw std::runtime_error("Error ! Date is anterior to first bitcoin value in database !");
			return (quantity * (*it).second);
		}
	}
	it2--;
	return quantity * (*it2).second;
}

BitcoinExchange::st_time BitcoinExchange::getDateValue(std::string value)
{
	BitcoinExchange::st_time ltm;
	if (std::isdigit(value[0]) == false || std::isdigit(value[1]) == false || std::isdigit(value[2]) == false || std::isdigit(value[3]) == false || value[4] != '-' || std::isdigit(value[5]) == false || std::isdigit(value[6]) == false || value[7] != '-' || std::isdigit(value[8]) == false || std::isdigit(value[9]) == false || value[10] != '\0')
	{
		ltm.day = -1;
		return (ltm);
	}
	int index = value.find_first_of('-', 0);
	ltm.year = std::atoi(value.substr(0, index).c_str());
	ltm.month = std::atoi(value.substr(index + 1, index + 3).c_str());
	ltm.day = std::atoi(value.substr(index + 4, index + 6).c_str());
	if (ltm.month > 12 || ((ltm.month == 1 || ltm.month == 3 || ltm.month == 5 || ltm.month == 7 || ltm.month == 8 || ltm.month == 10 || ltm.month == 12) && ltm.day > 31) ||
		((ltm.month == 4 || ltm.month == 6 || ltm.month == 9 || ltm.month == 11) && ltm.day > 30))
	{
		ltm.day = -2;
		return (ltm);
	}
	if (ltm.month == 2)
	{
		if (((ltm.year % 400 != 0) && (ltm.year % 4 != 0 || ltm.year % 100 == 0)) && ltm.day > 28)
		{
			ltm.day = -2;
			return (ltm);
		}
		else if (ltm.day > 29)
		{
			ltm.day = -2;
			return (ltm);
		}
	}
	if (ltm.day <= 0 || ltm.month <= 0 || ltm.year < 0)
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
	long unsigned int pos = sep + 3;
	int dot = 0;

	while (line[pos] != '\0')
	{
		if (line[pos] == '.' && dot != 0)
		{
			std::string ret = ("Error: Double . in line => " + line);
			throw std::runtime_error(ret);
		}
		else if (line[pos] == '.')
			dot++;
		else if ((line[pos] == '-' || line[pos] == '+') && pos != sep + 3)
		{
			std::string ret = ("Error: non digit char in line => " + line);
			throw std::runtime_error(ret);
		}
		else if (line[pos] == '-' || line[pos] == '+')
		{
			pos++;
			continue;
		}
		else if (std::isdigit(line[pos]) == false)
		{
			std::string ret = ("Error: non digit char in line => " + line);
			throw std::runtime_error(ret);
		}
		pos++;
	}
	if (pos == sep + 3)
	{
		std::string ret = ("Error: no value in line => " + line);
		throw std::runtime_error(ret);
	}
	else if (pos == sep + 4 && (line[pos - 1] == '-' || line[pos - 1] == '+'))
	{
		std::string ret = ("Error: no value in line => " + line);
		throw std::runtime_error(ret);
	}
	str_date = line.substr(0, sep);
	st_time date = getDateValue(str_date);
	if (date.day <= 0)
	{
		ret = ("Error: Bad input => " + str_date);
		throw std::runtime_error(ret);
	}
	double Quantity = 0;
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
	double valuated;
	std::stringstream s;
	if (this->_bitcoinValues.size() == 1)
	{
		if (((*this->_bitcoinValues.begin()).first <= date) == false)
		{
			throw std::runtime_error("Error ! Date is anterior to first bitcoin value in database !");
		}
		else
		{
			valuated = Quantity * (*this->_bitcoinValues.begin()).second;
		}
	}
	else
		valuated = getValue(date, Quantity);
	s << str_date << " => " << Quantity << " = " << std::fixed << std::setprecision(2) << valuated;
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
