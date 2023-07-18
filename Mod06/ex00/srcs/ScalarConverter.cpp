#include <ScalarConverter.hpp>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	if (&src == this)
		return (*this);
	return (*this);
}

void ScalarConverter::convert(std::string src)
{
	e_type type;

	type = getType(src);
	switch (type)
	{
		case FLOAT:
		{
			float	base = std::atof(src.c_str());
			int		inted = static_cast<int>(base);

			std::cout << "(Base)Float = " << std::fixed << base << 'f' << std::endl;
			std::cout << "Double = " << std::fixed << static_cast<double>(base) << std::endl;
			if (src == "nanf" || src == "+inff" || src == "-inff")
				std::cout << "Int = Impossible" << std::endl;
			else
				std::cout << "Int = " << inted << std::endl;
			if (inted > 31 && inted < 127)
				std::cout << "Char = '" << static_cast<char>(base) << "'" << std::endl;
			else if (inted >= 0 && inted <= 256)
				std::cout << "Char = Non Displayable" << std::endl;
			else
				std::cout << "Char = imposible" << std::endl;
			break;
		}
		case DOUBLE:
		{
			double	base = std::atof(src.c_str());
			int		inted = static_cast<int>(base);

			std::cout << "Float = " << static_cast<float>(base) << std::fixed << 'f' << std::endl;
			std::cout << "(Base)Double = " << std::fixed << base << std::endl;
			if (src == "nan" || src == "+inf" || src == "-inf")
				std::cout << "Int = Impossible" << std::endl;
			else
				std::cout << "Int = " << inted << std::endl;
			if (inted > 31 && inted < 127)
				std::cout << "Char = '" << static_cast<char>(base) << "'" << std::endl;
			else if (inted >= 0 && inted <= 256)
				std::cout << "Char = Non Displayable" << std::endl;
			else
				std::cout << "Char = imposible" << std::endl;
			break;
		}
		case INT:
		{
			int	base = std::atoi(src.c_str());

			std::cout << "Float = " << std::fixed << static_cast<float>(base) << 'f' << std::endl;
			std::cout << "Double = " << std::fixed << static_cast<double>(base) << std::fixed << std::endl;
			std::cout << "(Base)Int = " << base << std::endl;
			if (base > 31 && base < 127)
				std::cout << "Char = '" << static_cast<char>(base) << "'" << std::endl;
			else if (base >= 0 && base <= 256)
				std::cout << "Char = Non Displayable" << std::endl;
			else
				std::cout << "Char = imposible" << std::endl;
			break;
		}
		case CHAR:
		{
			char	base = src[0];

			std::cout << "Float = " << std::fixed << static_cast<float>(base) << 'f' << std::endl;
			std::cout << "Double = " << std::fixed << static_cast<double>(base) << std::endl;
			std::cout << "Int = " << static_cast<int>(base) << std::endl;
			if (base > 31 && base < 127)
				std::cout << "(Base)Char = '" << base << "'" << std::endl;
			break;
		}
		case INVALID:
		{
			std::cerr << "Invalid input" << std::endl;
			break;
		}
	default:
		break;
	}
}

bool ScalarConverter::isFloat(std::string src)
{
	int	dot_count = 0;
	int	f_count = 0;
	int	digit_count = 0;
	size_t start = 0;

	if (src[0] == '-' || src[0] == '+')
		start++;
	for (size_t i = start;  i < src.length(); i++)
	{
		if (src[i] == '.' && dot_count != 0)
			return (false);
		else if (src[i] == '.')
			dot_count++;
		if (src[i] == 'f' && (i != src.length() - 1 || i == 0))
			return (false);
		else if (src[i] == 'f')
			f_count++;
		if ((src[i] != 'f' && src[i] != '.') && (src[i] < '0' || src[i] > '9'))
			return(false);
		else if (src[i] >= '0' && src[i] <= '9')
			digit_count++;
	}
	if (f_count == 1 && digit_count > 0)
	{
		float floated = std::atof(src.c_str());
		std::ostringstream oss;
		oss << floated;
		std::string str = oss.str() + 'f';
		if (str == src)
			return (true);
	}
	return (false);
}

e_type ScalarConverter::getType(std::string src)
{
	if (isFloat(src) == true)
		return (FLOAT);
	if (isDouble(src) == true)
		return(DOUBLE);
	if (isInt(src) == true)
		return (INT);
	if (isChar(src) == true)
		return (CHAR);
	return (isPseudo(src));
}

bool ScalarConverter::isDouble(std::string src)
{
	int	dot_count = 0;
	int	digit_count = 0;
	size_t start = 0;

	if (src[0] == '-' || src[0] == '+')
		start++;
	for (size_t i = start;  i < src.length(); i++)
	{
		if (src[i] == '.' && dot_count != 0)
			return (false);
		else if (src[i] == '.')
			dot_count++;
		if (src[i] != '.' && (src[i] < '0' || src[i] > '9'))
			return(false);
		else if (src[i] >= '0' && src[i] <= '9')
			digit_count++;
	}
	if (dot_count == 1 && digit_count > 0)
	{
		double doubled = std::atof(src.c_str());
		std::ostringstream oss;
		oss << doubled;
		std::string str = oss.str();
		if(str == src)
			return (true);
	}
	return (false);
}

bool ScalarConverter::isInt(std::string src)
{
	int	digit_count = 0;
	size_t start = 0;

	if (src[0] == '-' || src[0] == '+')
		start++;
	for (size_t i = start;  i < src.length(); i++)
	{
		if (src[i] < '0' || src[i] > '9')
			return(false);
		else if (src[i] >= '0' && src[i] <= '9')
			digit_count++;
	}
	if (digit_count > 0)
	{
		int inted = std::atoi(src.c_str());
		std::ostringstream oss;
		oss << inted;
		std::string str = oss.str();
		if(str == src)
			return (true);
	}
	return (false);
}

bool ScalarConverter::isChar(std::string src)
{
	if (src.length() != 1)
		return (false);
	else if (src[0] > 31 && src[0] < 127)
		return (true);
	return (false);
}

e_type ScalarConverter::isPseudo(std::string src)
{
	if (src == "nanf")
		return (FLOAT);
	if (src == "+inff")
		return (FLOAT);
	if (src == "-inff")
		return (FLOAT);
	if (src == "nan")
		return (DOUBLE);
	if (src == "+inf")
		return (DOUBLE);
	if (src == "-inf")
		return (DOUBLE);
	return (INVALID);
}
