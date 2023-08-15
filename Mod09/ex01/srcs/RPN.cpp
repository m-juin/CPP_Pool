#include <RPN.hpp>

RPN::RPN()
{
}

bool RPN::calcul(long long num1, long long num2, char op)
{
	long long result = 0;
	switch (op)
	{
		case '+':
		{
			result = (num2 + num1);
			break;
		}
		case '-':
		{
			result = (num2 - num1);
			break;
		}
		case '/':
		{
			if (num1 == 0)
			{
				std::cerr << "Division by 0 invalid !" << std::endl;
				return (false);
			}
			result = (num2 / num1);
			break;
		}
		case '*':
		{
			result = (num2 * num1);
			break;
		}
		default:
		{
			std::cerr << "invalid operator \'" << op << "\'" << std::endl;
			return (false);
		}
	}
	if (result > 2147483647 || result < -2147483648)
	{
		std::cerr << "The calculation will exceed the limit of an int and cause an overflow (" << num2 << " " << op << " " << num1 << " = " << result << ")" << std::endl;
		return (false);
	}
	_value.push(result);
	return (true);
}

bool RPN::calculate(std::string data)
{
	int pos = -1;
	int spacecount = 0;
	while (data[++pos] != '\0')
	{
		if (data[pos] == ' ')
		{
			spacecount++;
			continue;
		}
		else if (data[pos] >= '0' && data[pos] <= '9')
		{
			_value.push(data[pos] - '0');
		}
		else
		{
			if (_value.size() < 2)
			{
				std::cout << "Invalid calcul Format" << std::endl;
				return (false);
			}
			int num1 = _value.top();
			_value.pop();
			int num2 = _value.top();
			_value.pop();
			if (calcul(num1, num2, data[pos]) == false)
				return (false);
		}
	}
	if (_value.size() != 1)
	{
		std::cout << "Invalid calcul Format" << std::endl;
		return (false);
	}
	return (true);
}

int RPN::getTop()
{
	return (_value.top());
}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &src)
{
	if (this == &src)
		return (*this);
	_value = src._value;
	return (*this);
}
